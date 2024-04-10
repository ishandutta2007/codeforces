#include<bits/stdc++.h>
#include<complex>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
    template<class S,class T>
    ostream &operator <<(ostream& out,const pair<S,T>& a){
        out<<'('<<a.fr<<','<<a.sc<<')';
        return out;
    }
}

typedef complex<lint> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
int n;
int sum[100005];


P ps[100005];
const lint INF2=2e18;

bool cmp(const P& a,const P& b){
    return a.imag()<b.imag();
}

P watch[100005];
lint rec(int l,int r){
    if(r-l<=3){
        lint res=INF2;
        REPN(i,r,l) REPN(j,i,l) chmin(res,norm(ps[i]-ps[j]));
        sort(ps+l,ps+r,cmp);
        return res;
    }
    int md=(l+r)>>1;
    int xdiv=ps[md].real();
    lint res=min(rec(l,md),rec(md,r));

    lint sqr=sqrt((double)res);

    inplace_merge(ps+l,ps+md,ps+r,cmp);
    
    int st=0,en=0;
    REPN(i,r,l) if(abs(ps[i].real()-xdiv)<=sqr){
        while(st<en && ps[i].imag()-watch[st].imag()>sqr) ++st;

        REPN(j,en,st) chmin(res,norm(watch[j]-ps[i]));
        watch[en++]=ps[i];
    }

    return res;
}
lint getclose(){
    sort(ps,ps+n);

    lint res=rec(0,n);

    return res;

}
int main(){
    cin>>n;
    REP(i,n){
        int a;scanf("%d",&a);
        sum[i+1]=sum[i]+a;
    }
    REP(i,n) ps[i]=P(i,sum[i+1]);
    
    lint res=getclose();

    cout<<res<<endl;

    return 0;
}