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

int N,M,Q;
int U[101000],V[101000];
vector<pair<int,int> > E[101000];
map<int,int> R[101000];
const int D=300;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y>>j;
        E[j-1].push_back(make_pair(x-1,y-1));
    }
    cin>>Q;
    FOR(i,Q) {
        cin>>U[i]>>V[i];
        R[--U[i]][--V[i]]=0;
    }
    FOR(i,M) if(E[i].size()) {
        if(E[i].size()<=D) {
            map<int,int> m;
            ITR(it,E[i]) m[it->first]=m[it->second]=0;
            x=0;
            ITR(it,m) it->second=x++;
            UF uf(x);
            ITR(it,E[i]) uf.unite(m[it->first],m[it->second]);
            ITR(it,m) ITR(it2,m) if(uf[it->second]==uf[it2->second] && R[it->first].count(it2->first)) R[it->first][it2->first]++;
        }
        else {
            UF uf(N);
            ITR(it,E[i]) uf.unite(it->first,it->second);
            FOR(j,N) ITR(it,R[j]) if(uf[j]==uf[it->first]) it->second++;
        }
    }
    FOR(i,Q) _P("%d\n",R[U[i]][V[i]]);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}