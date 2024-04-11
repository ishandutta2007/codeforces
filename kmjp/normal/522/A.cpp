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

map<string,int> M;
string S[3];
int N,ma;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    ma=M["polycarp"]=1;
    cin>>N;
    while(N--) {
        cin>>S[0]>>S[1]>>S[2];
        FORR(c,S[0]) c=tolower(c);
        FORR(c,S[2]) c=tolower(c);
        M[S[0]]=max(M[S[0]],M[S[2]]+1);
        ma=max(ma,M[S[0]]);
    }
    cout<<ma<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}