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

int R,C;
string S[101];

class UF {
    public:
    int um;
    vector<int> ufpar,ufrank,ufcnt;
    UF(int um_=100002) { um=um_; ufrank=vector<int>(um,0); ufcnt=vector<int>(um,1); for(int i=0;i<um;i++) ufpar.push_back(i);}
    int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
    int count(int x) { return ufcnt[operator[](x)];}
    void unite(int x,int y) {
        x = operator[](x); y = operator[](y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
        else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};

bool ok(int Y,int X) {
    char c=S[Y][X];
    int x,y;
    UF uf(10005);
    
    S[Y][X]='a';
    FOR(y,R) FOR(x,C) {
        if(y<R-1 && S[y][x]==S[y+1][x]) uf.unite(y*100+x,(y+1)*100+x);
        if(x<C-1 && S[y][x]==S[y][x+1]) uf.unite(y*100+x,y*100+x+1);
    }
    if(Y>0 && X>0 && S[Y-1][X]==c && S[Y][X-1]==c && uf[(Y-1)*100+X]==uf[Y*100+(X-1)]) return true;
    if(Y>0 && X<C-1 && S[Y-1][X]==c && S[Y][X+1]==c && uf[(Y-1)*100+X]==uf[Y*100+(X+1)]) return true;
    if(Y<R-1 && X>0 && S[Y+1][X]==c && S[Y][X-1]==c && uf[(Y+1)*100+X]==uf[Y*100+(X-1)]) return true;
    if(Y<R-1 && X<C-1 && S[Y+1][X]==c && S[Y][X+1]==c && uf[(Y+1)*100+X]==uf[Y*100+(X+1)]) return true;
    
    
    
    S[Y][X]=c;
    return false;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>R>>C;
    FOR(y,R) cin>>S[y];
    
    FOR(y,R) FOR(x,C) if(ok(y,x)) return _P("Yes\n");
    _P("No\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}