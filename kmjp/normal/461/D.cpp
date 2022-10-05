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

class UF {
    public:
    static const int ufmax=2000052;
    int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
    UF() { int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
    int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
    int count(int x) { return ufcnt[operator[](x)];}
    void unite(int x,int y) {
        x = operator[](x); y = operator[](y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
        else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};

int N,K;
UF uf;
ll mo=1000000007;

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>K;
    while(K--) {
        cin>>y>>x>>s;
        y--,x--;
        l = abs(x-y);
        r = x+y;
        if(r>=N) r-=2*(r-(N-1));
        if(s[0]=='x') uf.unite(l*2,(r+2)*2),uf.unite(l*2+1,(r+2)*2+1);
        else uf.unite(l*2,(r+2)*2+1),uf.unite(l*2+1,(r+2)*2);
    }
    int cnt=0;
    FOR(i,N+2) {
        if(uf[i*2]==uf[i*2+1]) return _P("0\n");
        if(uf[i*2]==i*2) cnt++;
        if(uf[i*2+1]==i*2+1) cnt++;
    }
    ll ret=1;
    FOR(i,(cnt-4)/2) ret=ret*2%mo;
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}