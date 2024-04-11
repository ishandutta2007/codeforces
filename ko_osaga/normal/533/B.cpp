#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pi;

int n, a[200005];
vector<int> graph[200005];
long long dp[200005][2];

long long f(int pos, int TK){
    if(graph[pos].size() == 0){
        if(TK == 1) return a[pos];
        return 0;
    }
    if(~dp[pos][TK]) return dp[pos][TK];
    long long dp0 = 0, dp1 = 0;
    for (int i=0; i<graph[pos].size(); i++) {
        if(i == 0){
            int j = graph[pos][i];
            dp0 = f(j,0);
            dp1 = f(j,1);
        }
        else{
            int j = graph[pos][i];
            long long TK0 = f(j,0);
            long long TK1 = f(j,1);
            long long ndp0 = max(dp0 + TK0, dp1 + TK1);
            long long ndp1 = max(dp1 + TK0, dp0 + TK1);
            dp0 = ndp0;
            dp1 = ndp1;
        }
    }
    if(TK == 0) return dp[pos][TK] = dp0;
    return dp[pos][TK] = max(dp0 + a[pos], dp1);
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        int p;
        scanf("%d %d",&p,&a[i]);
        if(p != -1) graph[p].push_back(i);
    }
    printf("%I64d",max(f(1,0),f(1,1)));
}