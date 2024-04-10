#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

int n;
vector<int> v[maxn];
int siz[maxn], val[maxn];

void dfs1(int i, int fa){
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs1(to, i);
		siz[i] += siz[to];
		val[i] = max(val[i], siz[to]);
	}
	val[i] = max(val[i], n - siz[i]);
} 

int dep[maxn];

void dfs2(int i, int fa){
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dep[to] = dep[i] + 1;
		dfs2(to, i);
		siz[i] += siz[to];
	}
}

bitset<maxn> bs;
int cnt[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++){
		int x;
		scanf("%d", &x);
		v[x].push_back(i), v[i].push_back(x);
	}
	dfs1(1, 0);
	ll ans = 0;
	int mn = *min_element(val + 1, val + 1 + n);
	for(int x = 1;x <= n;x++){
		if(val[x] == mn){
			dep[x] = 0;
			dfs2(x, 0);
			bs.reset();
			bs[0] = 1;
			for(auto to : v[x]) cnt[siz[to]]++;
			for(int i = 1;i <= n;i++) if(cnt[i]){
				int sum = cnt[i];
				int c = 1;
				while(sum > c){
					bs |= bs << (c * i);
					sum -= c;
					c <<= 1;
				}
				bs |= bs << (sum * i);
			}
			ll sum = n;
			for(int i = 1;i <= n;i++) sum += dep[i];
			for(int i = (n - 1) / 2;;i--){
				if(bs[i]){
					sum += 1ll * i * (n - 1 - i);
					break;
				}
			}
			ans = max(ans, sum);
		}
	}
	printf("%lld", ans);
}