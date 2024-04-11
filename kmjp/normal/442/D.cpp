#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
int P[1000002];
int dp[1000002];
int col[2][1000002];
void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    for(i=1;i<=N;i++) {
        cin>>P[i];
        P[i]--;
        int cur = i;
        dp[cur]=1;
        while(cur>0) {
            int pa=P[cur];
            // set first and second maxium
            if(dp[cur]>col[0][pa]) col[1][pa]=col[0][pa],col[0][pa]=dp[cur];
            else col[1][pa]=max(col[1][pa], dp[cur]);
            // add new color but not increase cost
            if(max(col[0][pa],col[1][pa]+1) <= dp[pa]) break;
            dp[pa]=max(col[0][pa],col[1][pa]+1);
            cur = pa;
        }
        _P("%d ",col[0][0]);
    }
    _P("\n");
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}