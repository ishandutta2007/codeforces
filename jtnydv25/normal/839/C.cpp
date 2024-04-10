#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
const int N = 100005;
vi con[N];
double dp[N];
void dfs(int s, int p){
	int cnt = 0;
	for(int v : con[s]){
		if(v != p){
			dfs(v, s);
			cnt++;
			dp[s] += (1 + dp[v]);
		}
	}
	if(cnt) dp[s] /= cnt;
}
int main(){
    int t = 1, n, u, v;
    // sd(t);
    while(t--){
        sd(n);
        for(int i = 1; i < n; i++){
        	sd(u), sd(v);
        	con[u].pb(v);
        	con[v].pb(u);
        }
        dfs(1, 0);
        printf("%.10lf\n", dp[1]);
    }
}