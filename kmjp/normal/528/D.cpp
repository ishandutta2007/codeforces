#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int SL,TL,K;
string S,T;
int cnt[1<<19];
int dif[1<<19];

typedef complex<double> Comp;

vector<Comp> fft(vector<Comp> v, bool rev=false) {
    int n=v.size(),i,j,m;
    
    for(i=0,j=1;j<n-1;j++) {
        for(int k=n>>1;k>(i^=k);k>>=1);
        if(i>j) swap(v[i],v[j]);
    }
    for(int m=2; m<=n; m*=2) {
        double deg=(rev?-1:1) * 2*acos(-1)/m;
        Comp wr(cos(deg),sin(deg));
        for(i=0;i<n;i+=m) {
            Comp w(1,0);
            for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
                Comp t1=v[j1],t2=w*v[j2];
                v[j1]=t1+t2, v[j2]=t1-t2;
                w*=wr;
            }
        }
    }
    if(rev) FOR(i,n) v[i]*=1.0/n;
    return v;
}

vector<Comp> MultPoly(vector<Comp> P,vector<Comp> Q) {
    P=fft(P), Q=fft(Q);
    for(int i=0;i<P.size();i++) P[i]*=Q[i];
    return fft(P,true);
}

void dodo(char c) {
    int i,num=0;
    ZERO(dif);
    vector<Comp> SC(1<<19,0),TC(1<<19,0);
    
    FOR(i,SL) if(S[i]==c) dif[max(0,i-K)]++, dif[min(SL,i+K+1)]--;
    FOR(i,SL) dif[i]+=i?dif[i-1]:0, SC[i]=dif[i]>0;
    FOR(i,TL) TC[i]=T[TL-1-i]==c, num+=T[i]==c;
    SC=MultPoly(SC,TC);
    
    FOR(i,SL-TL+1) cnt[i]+=(SC[i+TL-1].real()+1e-7>=num);
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>SL>>TL>>K;
    cin>>S>>T;
    
    dodo('A');
    dodo('T');
    dodo('G');
    dodo('C');
    cout<<count(cnt,cnt+(SL-TL+1),4)<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}