#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n;
int a[maxn], b[maxn];
vector<int> v[2];
ll ans;

void solve(){
	ll sum = 0;
	int last = 0;
	vector<int> w[2];
	w[0] = v[0], w[1] = v[1];
	for(int i = 1;i <= n;i++){
		int j = i & 1;
		if(w[j].empty()) j ^= 1;
		if(i == 1){
			sum += w[j][0];
			w[j].erase(w[j].begin());
			last = j;
			continue;
		}
		sum += w[j].back();
		if(last != j) sum += w[j].back();
		last = j;
		w[j].pop_back();
	}
	ans = max(ans, sum);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		v[0].clear(), v[1].clear();
		for(int i = 1;i <= n;i++) v[a[i]].push_back(b[i]);
		for(int i = 0;i <= 1;i++) sort(v[i].begin(), v[i].end());
		ans = 0;
		solve();
		swap(v[0], v[1]);
		solve();
		printf("%lld\n", ans);
	}
}