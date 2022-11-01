#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
ll r;
int l[maxn], t[maxn];

vector<ll> v;
ll ans;

int main(){
	scanf("%d%lld", &n, &r);
	for(int i = 1;i <= n;i++) scanf("%d", &l[i]);
	for(int i = 1;i <= n;i++){
		scanf("%d", &t[i]);
		if(t[i] < l[i]) return printf("-1"), 0;
	}
	ll x = 0, y = 0;
	for(int i = 1;i <= n;i++){
		if(x >= l[i]){
			x -= l[i];
			continue;
		}
		l[i] -= x, t[i] -= x;
		x = 0;
		if(t[i] >= 2 * l[i]){
			y += 2 * l[i]; 
			continue;
		}
		y += 2 * (t[i] - l[i]);
		l[i] -= t[i] - l[i];
		int cnt = (l[i] + r - 1) / r;
		ans += cnt;
		for(int j = 0;j < cnt && v.size() <= 1e5;j++) v.push_back(y + j * r);
		x = cnt * r - l[i];
		y += cnt * r;
	}
	printf("%lld\n", ans);
	if(ans <= 1e5) for(int i = 0;i < v.size();i++) printf("%lld ", v[i]);
}