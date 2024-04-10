#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;
const ll M = ll(1e9) + 7;

int n, k, v[N];
vector<int> e[N];
ll r;

int f(int x, int y){
	v[x] = 1;
	for(int i : e[x]) if(i != y) v[x] += f(i, x);
	return v[x];
}

int main(){
	scanf("%d%d", &n, &k);
	r = 1; for(int i = 0; i < k; i++) r = r * n % M;
	for(int i = 0, x, y, z; i < n - 1; i++){
		scanf("%d%d%d", &x, &y, &z);
		if(z) continue;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		if(v[i]) continue;
		ll t = f(i, 0);
		ll tt = 1; for(int j = 0; j < k; j++) tt = tt * t % M;
		r = (r + M - tt) % M;
	}
	printf("%lld\n", r);
}