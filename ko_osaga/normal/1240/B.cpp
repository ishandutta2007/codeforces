#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
#define sz(v) ((int)(v).size())
using pi = pair<int, int>;
using lint = long long;

int n, arr[MAXN];
int l[MAXN], r[MAXN];

int main(){
	int q; cin >> q;
	while(q--){
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%d",&arr[i]);
		fill(l, l + n + 1, 1e9);
		fill(r, r + n + 1, -1);
		for(int i=0; i<n; i++){
			l[arr[i]] = min(l[arr[i]], i);
			r[arr[i]] = max(r[arr[i]], i);
		}
		vector<pi> v;
		for(int i=1; i<=n; i++){
			if(l[i] <= r[i]) v.emplace_back(l[i], r[i]);
		}
		int ans = 0;
		for(int i=0; i<sz(v); ){
			int e = i+1;
			while(e < sz(v) && v[e-1].second < v[e].first) e++;
			ans = max(ans, e - i);
			i = e;
		}
		printf("%d\n", sz(v) - ans);
	}
}