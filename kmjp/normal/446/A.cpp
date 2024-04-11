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
vector<int> V;

int dp[2][100001];
int pre=-1;

void solve() {
    int f,i,j,k,l,x,y;
    int ma=0;
    
    cin>>N;
    FOR(i,N) {
        cin>>x;
        V.push_back(x);
    }
    
    dp[0][0]=dp[1][N-1]=1;
    FOR(i,N-1) dp[0][i+1]=(V[i]<V[i+1])?dp[0][i]+1:1;
    for(i=N-2;i>=0;i--) dp[1][i]=(V[i]<V[i+1])?dp[1][i+1]+1:1;
    FOR(i,N) ma=max(ma,dp[0][i]+1);
    FOR(i,N) ma=max(ma,dp[1][i]+1);
    for(i=1;i<N-1;i++) if(V[i-1]+2<=V[i+1]) ma=max(ma,dp[0][i-1]+1+dp[1][i+1]);
    
    ma=min(ma,N);
    cout << ma << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}