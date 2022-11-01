#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n;
pair<ll, ll> a[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld%lld", &a[i].second, &a[i].first);
	sort(a + 1, a + 1 + n);
	int r = n;
	ll sum = 0, ans = 0;
	for(int i = 1;i <= r;i++){
		while(sum < a[i].first && i <= r){
			ll mn = min(a[i].first - sum, a[r].second);
			sum += mn, ans += 2 * mn, a[r].second -= mn;
			if(a[r].second == 0) r--;
		}
		sum += a[i].second, ans += a[i].second;
	}
	printf("%lld", ans);
}