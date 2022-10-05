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

int K;
string S;
map<char,int> SS;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>K>>S;
    FOR(i,S.size()) if(SS.count(S[i])==0) SS[S[i]]=i;
    
    if(SS.size()<K) return _P("NO\n");
    
    vector<int> V;
    FORR(r,SS) V.push_back(r.second);
    sort(ALL(V));
    while(V.size()>K) V.pop_back();
    V.push_back(S.size());
    cout<<"YES"<<endl;
    FOR(i,K) cout<<S.substr(V[i],V[i+1]-V[i])<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}