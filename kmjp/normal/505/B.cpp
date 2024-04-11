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
    static const int ufmax=102;
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

int N,M,Q;
UF uf[102];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y>>r;
        uf[r].unite(x,y);
    }
    cin>>Q;
    while(Q--) {
        cin>>x>>y;
        j=0;
        FOR(i,101) j += uf[i][x]==uf[i][y];
        cout<<j<<endl;
        
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}