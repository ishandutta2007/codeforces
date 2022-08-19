#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;

int n;
char str[MAXN];
int dp[MAXN];

vector<string> v = {"RL", "RRL", "RLL", "RRLL"};

int solve(){
	for(int i=1; i<=n; i++){
		dp[i] = 0;
		for(auto &j : v){
			if(sz(j) <= i){
				int tmp = dp[i - sz(j)];
				for(int k=0; k<sz(j); k++){
					if(str[i - sz(j) + k] == j[k]){
						tmp++;
					}
				}
				dp[i] = max(dp[i], tmp);
			}
		}
	}
	return dp[n];
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		scanf("%s", str);
		int ret = 0;
		for(int i=0; i<4; i++){
			ret = max(ret, solve());
			rotate(str, str + 1, str + n);
		}
		printf("%d\n", n - ret);
	}
}