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

ll N;
ll mo=1000000007;
ll memo[32][32][3];

ll dfs(int dig,int vec,int any) {
    if(dig<0) return 1;
    ll& ret=memo[dig][vec][any];
    if(ret>=0) return ret;
    bool any2=(N&(1LL<<dig))!=0;
    ret = 0;
    // new vector
    if(any||any2) ret += dfs(dig-1,vec+1,any);
    
    if(vec==0) {
        ret += dfs(dig-1,vec,any||any2);
    }
    else {
        // not take
        ret += dfs(dig-1,vec,any || any2) * (1LL<<(vec-1));
        if(any||any2) ret += dfs(dig-1,vec,any) * (1LL<<(vec-1));
    }
    return ret%=mo;
}


void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N;
    MINUS(memo);
    cout<<dfs(30,0,0)%mo<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}