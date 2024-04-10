#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;
typedef long long ll;

ll x[MAXN], y[MAXN];
ll d[MAXN];

ll sqr(ll x){
	return x * x;
}

ll dis(int p, int q){
	return sqr(x[p]- x[q]) + sqr(y[p] - y[q]);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n + 2; i++)
		scanf("%lld%lld", &x[i], &y[i]);
	for(int i = 3; i <= n + 2; i++)
		d[i - 2] = dis(1, i);
	d[0] = 0;
	sort(d + 1, d + n + 1);
	ll ans = 1e18 + 10;
	for(int i = 0; i <= n; i++){
		ll k = 0;
		for(int j = 3; j <= n + 2; j++)
			if (dis(1, j) > d[i])
				k = max(k, dis(2, j));
		ans = min(ans, d[i] + k);
	//	cout<<d[i]<<' ' <<k<<endl;
	}
	cout<<ans<<endl;
	return 0;
}