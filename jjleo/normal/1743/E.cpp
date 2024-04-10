#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

typedef long long ll;

int p[2];
ll t[2];
int h, s;
ll f[maxn];

void Min(ll &x, ll y){
	x = min(x, y);
}

int main(){
	scanf("%d%lld%d%lld%d%d", &p[0], &t[0], &p[1], &t[1], &h, &s);
	ll ans = 1e18;
	for(int i = 1;i < h;i++) f[i] = 1e18;
	for(int i = 0;i < h;i++){
		ll a[2] = {t[0], t[1]};
		int now = i;
		ll val = f[i];
		while(1){
			if(now >= h){
				ans = min(ans, val);
				break;
			}
			if(now + p[0] + p[1] - s >= h) Min(ans, val + max(a[0], a[1]));
			else Min(f[now + p[0] + p[1] - s], val + max(a[0], a[1]));
			if(a[0] < a[1]){
				now += p[0] - s;
				val += a[0];
				a[1] -= a[0];
				a[0] = t[0];
			}else if(a[0] > a[1]){
				now += p[1] - s;
				val += a[1];
				a[0] -= a[1];
				a[1] = t[1];
			}else break;
		}
	}
	printf("%lld", ans);
}