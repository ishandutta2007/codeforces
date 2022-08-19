#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 3005;

vector<int> gph[MAXN];
int dp[MAXN][MAXN];

int f(int x, int y){
	if(x >= y) return 0;
	if(~dp[x][y]) return dp[x][y];
	int ret = max(f(x + 1, y), f(x, y - 1));
	for(auto &z : gph[x]){
		if(z <= y) ret = max(ret, f(x, z - 1) + f(z, y) + 1);
	}
	return dp[x][y] = ret;
}

void solve(){
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	for(int i = 0; i < n; i++){
		gph[i].clear();
		for(int j = i + 1; j < n; j++){
			if(a[i] == a[j]) gph[i].push_back(j);
		}
		fill(dp[i], dp[i] + n + 1, -1);
	}
	printf("%d\n", n - 1 - f(0, n - 1));
}

int main(){
	int tc; scanf("%d",&tc);
	for(int i = 1; i <= tc; i++){
		solve();
	}
}