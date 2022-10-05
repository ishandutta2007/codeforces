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

vector<int> V[29*27*27*27];

string S;
int L,Q;
map<pair<string,string>,int> M;

void solve() {
    int i,j,k,l,r,x,y; string s,t;
    
    cin>>S>>Q;
    L=S.size();
    
    FOR(i,L) {
        S[i]-='a'-1;
        V[S[i]].push_back(i);
        if(i-1>=0) V[S[i-1]*27+S[i]].push_back(i-1);
        if(i-2>=0) V[S[i-2]*27*27+S[i-1]*27+S[i]].push_back(i-2);
        if(i-3>=0) V[S[i-3]*27*27*27+S[i-2]*27*27+S[i-1]*27+S[i]].push_back(i-3);
    }
    
    while(Q--) {
        cin>>s>>t;
        x=y=0;
        ITR(it,s) *it-='a'-1, x=x*27+*it;
        ITR(it,t) *it-='a'-1, y=y*27+*it;
        
        if(V[x].empty() || V[y].empty()) {
            M[make_pair(s,t)] = -1;
        }
        else if(M.count(make_pair(s,t))==0) {
            int ret=1<<30;
            vector<int>::iterator si=V[x].begin(),ti=V[y].begin();
            while(si!=V[x].end() && ti!=V[y].end()) {
                ret=min(ret,(int)(max(*si+s.size(),*ti+t.size())-min(*si,*ti)));
                if(*si<*ti) si++;
                else ti++;
            }
            
            M[make_pair(s,t)]=(ret>=1<<30) ? -1 : ret;
        }
        cout<<M[make_pair(s,t)]<<endl;
    }
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}