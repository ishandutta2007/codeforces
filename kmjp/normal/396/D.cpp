#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];
    int lower_bound(V val) {
        V tv=0; int i,ent=0;
        for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
        return ent;
    }
    V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
    void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<int,21> bt;

ll numinv[1010000];
ll mo=1000000007;
ll P[1010000];
int N,A[1010000];

BIT<int,21> bit;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    P[0]=P[1]=1;
    for(i=2;i<=1001000;i++) {
        numinv[i]=(i*numinv[i-1]+1LL*i*(i-1)/2%mo*P[i-1]) % mo;
        P[i]=P[i-1]*i%mo;
    }
    
    cin>>N;
    FOR(i,N) bit.update(i+1,1);
    ll ls=0;
    ll ret=0;
    FOR(i,N) {
        cin>>x;
        y=bit.total(x-1);
        // less than x
        ret += y*P[N-i-1]%mo*ls+1LL*y*(y-1)/2%mo*P[N-i-1]+y*numinv[N-i-1];
        ret %= mo;
        // take x
        ls = (ls+y)%mo;
        bit.update(x,-1);
    }
    ret += ls;
    
    
    
    cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}