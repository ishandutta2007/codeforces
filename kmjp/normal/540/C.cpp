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

template<int um> class UF {
    public:
    vector<int> par,rank,cnt;
    UF() {rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par.push_back(i);}
    int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
    int count(int x) { return cnt[operator[](x)];}
    int operator()(int x,int y) {
        if((x=operator[](x))==(y=operator[](y))) return x;
        cnt[y]=cnt[x]=cnt[x]+cnt[y];
        if(rank[x]>rank[y]) return par[x]=y;
        rank[x]+=rank[x]==rank[y]; return par[y]=x;
    }
};
UF<500000> uf;

int H,W;
string S[1010];
int X[2],Y[2];

int getadjok(int y,int x) {
    int num=0;
    if(y>0 && S[y-1][x]=='.') num++;
    if(y<H-1 && S[y+1][x]=='.') num++;
    if(x>0 && S[y][x-1]=='.') num++;
    if(x<W-1 && S[y][x+1]=='.') num++;
    return num;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>H>>W;
    
    FOR(y,H) cin>>S[y];
    FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
        if(x<W-1 && S[y][x+1]=='.') uf(y*500+x,y*500+x+1);
        if(y<H-1 && S[y+1][x]=='.') uf(y*500+x,(y+1)*500+x);
    }
    FOR(i,2) cin>>Y[i]>>X[i], Y[i]--,X[i]--;
    
    if(abs(X[1]-X[0])+abs(Y[1]-Y[0])<=1) {
        int adj=abs(X[1]-X[0])+abs(Y[1]-Y[0]);
        if(S[Y[1]][X[1]]=='.' && getadjok(Y[1],X[1])+adj>=2) return _P("YES\n");
        if(S[Y[1]][X[1]]=='X' && getadjok(Y[1],X[1])+adj>=1 && H*W>1) return _P("YES\n");
    }
    else if(S[Y[1]][X[1]]=='.') {
        int ok=0;
        FOR(i,4) {
            int dd[]={-1,0,1,0};
            int ty=Y[0]+dd[i],tx=X[0]+dd[i^1];
            if(tx>=0 && tx<W && ty>=0 && ty<H && uf[ty*500+tx]==uf[Y[1]*500+X[1]] && S[ty][tx]!='X') ok=1;
        }
        if(ok && getadjok(Y[1],X[1])>=2) return _P("YES\n");
    }
    else {
        FOR(i,16) {
            int dd[]={-1,0,1,0};
            int ty=Y[0]+dd[i%4],tx=X[0]+dd[(i%4)^1];
            int sy=Y[1]+dd[i/4],sx=X[1]+dd[(i/4)^1];
            if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
            if(sx<0 || sx>=W || sy<0 || sy>=H) continue;
            if(uf[ty*500+tx]==uf[sy*500+sx] && S[ty][tx]!='X' && S[sy][sx]!='X') return _P("YES\n");
        }
    }
    _P("NO\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}