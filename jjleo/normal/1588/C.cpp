#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

int t, n;
vector<int> v[2];
map<ll, vector<int> > mp[2];
int a[maxn];
ll sum[2][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		v[0].clear(), v[1].clear(), mp[0].clear(), mp[1].clear();
		mp[0][0].push_back(0), mp[1][0].push_back(0), v[0].push_back(0);
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			sum[i & 1][i] = sum[i & 1][i - 1] + a[i];
			sum[i & 1 ^ 1][i] = sum[i & 1 ^ 1][i - 1] - a[i];
			int L = 0;
			for(int j = 0;j <= 1;j++){
				if(!v[j].empty() && sum[j][i] - sum[j][v[j][0]] > 0){
					int l = 0, r = v[j].size() - 1, mid;
					while(l < r){
						mid = (l + r >> 1) + 1;
						if(sum[j][i] - sum[j][v[j][mid]] > 0) l = mid;
						else r = mid - 1;
					}
					L = max(L, v[j][l] + 1);
				}
				if((i & 1) == j){
					while(!v[j].empty() && sum[j][v[j].back()] >= sum[j][i]) v[j].pop_back();
					v[j].push_back(i);
				}
			}
			ans += mp[i & 1][sum[i & 1][i]].end() - lower_bound(mp[i & 1][sum[i & 1][i]].begin(), mp[i & 1][sum[i & 1][i]].end(), L);
			for(int j = 0;j <= 1;j++) mp[j][sum[j & 1][i]].push_back(i);
			//printf("%d %lld--\n", i, ans);
		}
		printf("%lld\n", ans);
	}
}
/*
1
7
1 3 2 2 2 2 2
*/