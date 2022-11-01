#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

int t, n, a[maxn];
ll ans;

void solve(int mx){
	{
		ll cnt[2] = {0};
		for(int i = 1;i <= n;i++) cnt[0] += (mx - a[i]) / 2, cnt[1] += (mx - a[i]) & 1;
		if(cnt[0] > cnt[1]){
			ll val = (cnt[0] - cnt[1]) / 3;
			cnt[0] -= val;
			cnt[1] += val * 2;
		}
		ll mn = min(cnt[0], cnt[1]), sum = 0;
		cnt[0] -= mn, cnt[1] -= mn;
		sum += mn * 2;
		if(cnt[0]) sum += cnt[0] * 2;
		if(cnt[1]) sum += cnt[1] * 2 - 1;
		ans = min(ans, sum);
	}
	{
		ll cnt[2] = {0};
		for(int i = 1;i <= n;i++) cnt[0] += (mx - a[i]) / 2, cnt[1] += (mx - a[i]) & 1;
		if(cnt[0] > cnt[1]){
			ll val = (cnt[0] - cnt[1]) / 3;
			if(val) val--;
			cnt[0] -= val;
			cnt[1] += val * 2;
		}
		ll mn = min(cnt[0], cnt[1]), sum = 0;
		cnt[0] -= mn, cnt[1] -= mn;
		sum += mn * 2;
		if(cnt[0]) sum += cnt[0] * 2;
		if(cnt[1]) sum += cnt[1] * 2 - 1;
		ans = min(ans, sum);
	}
	{
		ll cnt[2] = {0};
		for(int i = 1;i <= n;i++) cnt[0] += (mx - a[i]) / 2, cnt[1] += (mx - a[i]) & 1;
		if(cnt[0] > cnt[1]){
			ll val = (cnt[0] - cnt[1]) / 3;
			if(val + 1 <= cnt[0]) val++;
			cnt[0] -= val;
			cnt[1] += val * 2;
		}
		ll mn = min(cnt[0], cnt[1]), sum = 0;
		cnt[0] -= mn, cnt[1] -= mn;
		sum += mn * 2;
		if(cnt[0]) sum += cnt[0] * 2;
		if(cnt[1]) sum += cnt[1] * 2 - 1;
		ans = min(ans, sum);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int mx = *max_element(a + 1, a + 1 + n);
		ans = 1e18;
		for(int i = 0;i <= 10;i++) solve(mx + i);
		printf("%lld\n", ans);
	}
}