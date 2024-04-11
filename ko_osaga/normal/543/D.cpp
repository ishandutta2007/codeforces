#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lint;
const int mod = 1e9 + 7;

int n, par[200005];
lint dp[200005], high[200005];

vector<int> graph[200005];
vector<lint> pfx[200005], sfx[200005];

int main(){
	scanf("%d",&n);
	for (int i=2; i<=n; i++) {
		scanf("%d",&par[i]);
		graph[par[i]].push_back(i);
	}
	for(int i=n; i; i--){
		dp[i] = 1;
		for(auto &j : graph[i]){
			dp[i] *= dp[j] + 1;
			dp[i] %= mod;
		}
	}
	for(int i=1; i<=n; i++){
		pfx[i].resize(graph[i].size());
		sfx[i].resize(graph[i].size());
		for(int j=0; j<graph[i].size(); j++){
			if(j) pfx[i][j] = pfx[i][j-1];
			else pfx[i][j] = 1;
			pfx[i][j] *= (dp[graph[i][j]] + 1);
			pfx[i][j] %= mod;
		}
		for(int j=graph[i].size()-1; j>=0; j--){
			if(j != graph[i].size()-1) sfx[i][j] = sfx[i][j+1];
			else sfx[i][j] = 1;
			sfx[i][j] *= (dp[graph[i][j]] + 1);
			sfx[i][j] %= mod;
		}
	}
	printf("%lld ",dp[1]);
	high[1] = 1;
	for (int i=2; i<=n; i++) {
		int x = par[i];
		int p = lower_bound(graph[x].begin(), graph[x].end(), i) - graph[x].begin();
		lint lo = (p ? pfx[x][p-1] : 1);
		lint hi = (p + 1 < graph[x].size() ? sfx[x][p+1] : 1);
		high[i] = (high[x] * lo % mod) * hi % mod + 1;
		printf("%lld ",dp[i] * high[i] % mod);
	}
}