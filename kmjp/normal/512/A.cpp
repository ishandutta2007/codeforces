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

class TopologicalSort {
public:
    static const int MV = 100;
    int NV,NIE[MV];
    vector<int> OutEdge[MV];
    
    TopologicalSort(int nv){init(nv);}
    void init(int nv) { NV=nv; for(int i=0;i<NV;i++) OutEdge[i].clear(), NIE[i]=0;}
    void add_edge(int x,int y) { OutEdge[x].push_back(y); NIE[y]++;}
    
    vector<int> sort() {
        int i,nv=0;
        vector<int> NI,R;
        NI.reserve(NV);
        R.reserve(NV);
        queue<int> S;
        FOR(i,NV) {
            NI.push_back(NIE[i]);
            nv+=OutEdge[i].size();
            if(NIE[i]==0) S.push(i);
        }
        
        while(!S.empty()) {
            int cur=S.front();
            S.pop();
            R.push_back(cur);
            ITR(it,OutEdge[cur]){
                nv--;
                if(--NI[*it]==0) S.push(*it);
            }
        }
        if(nv) return vector<int>();
        return R;
    }
};

int N;
string S[1010];
int mat[27][27];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>S[i];
    FOR(i,N-1) {
        bool hoge=false;
        FOR(j,min(S[i].size(), S[i+1].size())) {
            if(S[i][j]!=S[i+1][j]) {
                mat[S[i][j]-'a'][S[i+1][j]-'a']=1;
                hoge=true;
                break;
            }
        }
        if(hoge==false && S[i].size()>S[i+1].size()) return _P("Impossible\n");
    }
    
    TopologicalSort ts(26);
    FOR(i,26) FOR(j,26) if(mat[i][j]) ts.add_edge(i,j);
    vector<int> v=ts.sort();
    if(v.empty()) {
        _P("Impossible\n");
    }
    else {
        FOR(i,26) _P("%c",'a'+v[i]);
        _P("\n");
    }
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}