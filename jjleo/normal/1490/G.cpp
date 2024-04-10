#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n, m;
ll a[maxn];
vector<pair<ll, int> > v;
ll x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		v.clear();
		v.push_back({0, 0});
		for(int i = 1;i <= n;i++){
			scanf("%lld", &a[i]);
			a[i] += a[i - 1];
			if(a[i] > v.back().first) v.push_back({a[i], i});
		}
		while(m--){
			scanf("%lld", &x);
			ll ans = 0;
			if(x > v.back().first){
				if(a[n] <= 0){
					printf("-1 ");
					continue;
				}
				ll cnt = (x - v.back().first + a[n] - 1) / a[n];
				ans += cnt * n;
				x -= cnt * a[n];
			}
			ans += v[lower_bound(v.begin(), v.end(), (pair<ll, int>){x, 0}) - v.begin()].second;
			printf("%lld ", ans - 1);
		}
		puts("");
	}
}