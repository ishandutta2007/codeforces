#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

static const int ufmax=3000*6005;
int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
class UF {
    public:
    UF() { init();}
    void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
    int find(int x) {   return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
    int operator[](int x) {return find(x);}
    int count(int x) {return ufcnt[find(x)];}
    void unite(int x,int y) {
        x = find(x); y = find(y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
        else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};

int H,W,N,ret;
int C[3001][6005];
UF uf;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>H>>W>>N;
    if(W==1) return _P("0\n");
    
    FOR(i,N) {
        cin>>y>>x;
        y--;x--;
        set<int> A1,A2,A3;
        
        for(int dy=-1;dy<=1;dy++) for(int dx=-1;dx<=1;dx++) {
            int ty=y+dy,tx=(x+dx+2*W)%(2*W);
            if(ty>=0 && ty<H && C[ty][tx]) A1.insert(uf[ty*6005+tx]);
            tx=(tx+W)%(2*W);
            if(ty>=0 && ty<H && C[ty][tx]) A2.insert(uf[ty*6005+tx]);
        }
        set_intersection(A1.begin(),A1.end(),A2.begin(),A2.end(),inserter(A3,A3.begin()));
        if(A3.size()) continue;
        
        ret++;
        C[y][x]=C[y][x+W]=1;
        for(int dy=-1;dy<=1;dy++) for(int dx=-1;dx<=1;dx++) {
            int ty=y+dy,tx=(x+dx+2*W)%(2*W);
            if(ty>=0 && ty<H && C[ty][tx]) uf.unite(ty*6005+tx,y*6005+x);
            tx=(tx+W)%(2*W);
            if(ty>=0 && ty<H && C[ty][tx]) uf.unite(ty*6005+tx,y*6005+x+W);
        }
    }
    cout << ret << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}