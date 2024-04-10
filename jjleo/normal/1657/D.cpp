#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

int n, C, m;
ll a[maxn];
ll f[maxn];
vector<int> v[maxn];

int main(){
	scanf("%d%d", &n, &C);
	for(int i = 1;i <= n;i++){
		int c, d, h;
		scanf("%d%d%d", &c, &d, &h);
		a[c] = max(a[c], 1ll * d * h);
	}
	for(int i = 1;i <= C;i++) for(int j = i;j <= C;j += i) v[j].push_back(i);
	for(int i = 1;i <= C;i++){
		f[i] = f[i - 1];
		for(auto j : v[i]) f[i] = max(f[i], (i / j) * a[j]);
	}
	scanf("%d", &m);
	while(m--){
		ll x, y;
		scanf("%lld%lld", &x, &y);
		x *= y;
		x++;
		if(f[C] < x) printf("-1 ");
		else printf("%d ", lower_bound(f + 1, f + 1 + C, x) - f);
	}
}