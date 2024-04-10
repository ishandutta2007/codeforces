#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, s[200010], chk[200010];
vector<int> e[200010];

int sf(int x, int p){
	s[x] = 1;
	for(auto &i : e[x]){
		if(chk[i] || i == p) continue;
		s[x] += sf(i, x);
	}
	return s[x];
}

int cf(int t, int x, int p){
	for(auto &i : e[x]){
		if(chk[i] || i == p) continue;
		if(s[i] > t / 2) return cf(t, i, x);
	}
	return x;
}

int cen(int x){
	sf(x, 0);
	return cf(s[x], x, 0);
}

void g(ll *a, ll *b, int x, int p, int d){
	a[d % k] += d / k;
	b[d % k]++;
	for(auto &i : e[x]){
		if(chk[i] || i == p) continue;
		g(a, b, i, x, d + 1);
	}
}

ll f(int x){
	x = cen(x);
	chk[x] = 1;
	ll ta[5] = {}, tb[5] = {};
	ll ret = 0;
	for(auto &nx : e[x]){
		if(chk[nx]) continue;
		ll ca[5] = {}, cb[5] = {};
		g(ca, cb, nx, x, 1);
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				ret += (ta[i] * cb[j]) + (tb[i] * ca[j]) + (((i + j + k - 1) / k) * tb[i] * cb[j]);
			}
		}
		for(int i = 0; i < k; i++){
			ta[i] += ca[i];
			tb[i] += cb[i];
		}
		ret += f(nx);
	}
	for(int i = 0; i < k; i++) ret += ta[i] + (!!i) * tb[i];
	return ret;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0, x, y; i < n - 1; i++){
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	printf("%lld\n", f(1));
}