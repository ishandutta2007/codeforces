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

template<int MV> class UndirectedEulerPath {
public:
    vector<int> path;
    multiset<int> E[MV];
    void add_path(int x,int y) { E[x].insert(y); E[y].insert(x); }
    
    void dfs(int cur) {
        while(E[cur].size()) {
            int tar=*E[cur].begin();
            E[cur].erase(E[cur].begin());
            E[tar].erase(E[tar].find(cur));
            dfs(tar);
        }
        path.push_back(cur);
    }
    
    bool GetPath() {
        int fo=-1,odd=0,i,np=0;
        FOR(i,MV) {
            np += E[i].size();
            if(E[i].size()%2) odd++, fo=(fo==-1)?i:fo;
        }
        if(odd!=0 && odd!=2) return false;
        dfs(odd?fo:0);
        reverse(path.begin(),path.end());
        return path.size()==np/2+1;
    }
};


int N,M;
int in[101000];
multiset<int> E[101000];
UndirectedEulerPath<101000> uep;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y;
        x--,y--;
        if(x>y) swap(x,y);
        E[x].insert(y);
        in[x]++;
        in[y]++;
    }
    int odd=-1;
    FOR(i,N) {
        if(in[i]%2) {
            if(odd==-1) odd=i;
            else E[odd].insert(i), in[i]++, in[odd]++, odd=-1;
        }
    }
    
    
    FOR(i,N) FORR(r,E[i]) uep.add_path(i,r);
    
    uep.GetPath();
    vector<int> V=uep.path;
    if(V.size()%2==0) V.push_back(*V.begin());
    
    _P("%d\n",V.size()-1);
    FOR(i,V.size()-1) {
        if(i%2) _P("%d %d\n",V[i]+1,V[i+1]+1);
        else _P("%d %d\n",V[i+1]+1,V[i]+1);
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}