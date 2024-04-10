#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 300005;

ll m, r;
int a, b, g, d[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;

ll f(ll x){
	ll c = x / g;
	ll s = c * (c + 1) / 2;
	return c * (m + 1) - g * s;
}

int main(){
	scanf("%lld%d%d", &m, &a, &b);
	fill(d + 1, d + N, N);
	pq.emplace(0, 0);
	while(!pq.empty()){
		int x, y; tie(x, y) = pq.top();
		pq.pop();
		if(x != d[y]) continue;
		if(y + a < N && d[y + a] > max(x, y + a)){
			d[y + a] = max(x, y + a);
			pq.emplace(d[y + a], y + a);
		}
		if(y - b >= 0 && d[y - b] > max(x, y - b)){
			d[y - b] = max(x, y - b);
			pq.emplace(d[y - b], y - b);
		}
	}
	for(int i = 0; i < N; i++) if(d[i] < N) r += max(0LL, m - d[i] + 1);
	g = gcd(a, b);
	if(m >= N) r += f(m) - f(N - 1);
	printf("%lld\n", r);
}