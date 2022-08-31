// shirley smokes weed
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 400;

int n, m, s[MAXN], e[MAXN], x[MAXN];
int dp[1 << 18], indep[1 << 18], w[1 << 18], tk[1 << 18];

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		auto go = [&](){
		for(int i = 0; 3 * i <= n; i++){
			for(int j = 0; 3 * i + 5 * j <= n; j++){
				int k = n - 3 * i - 5 * j;
				if(k % 7 == 0){
					printf("%d %d %d\n", i, j, k/7);
					return;
				}
			}
		}
		puts("-1");
		};go();
	}
}