#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2005;
const ll INF = ll(1e18);

int n, m, k, b[N];
ll a[N], d[N];
priority_queue<int> pq;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int x; n--; ){
		scanf("%d", &x);
		pq.push(x);
		if(pq.size() > k) pq.pop();
	}
	n = k;
	for(int i = n; i >= 1; i--){
		a[i] = pq.top();
		pq.pop();
	}
	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	for(int x, y; m--; ){
		scanf("%d%d", &x, &y);
		if(x <= n) b[x] = max(b[x], y);
	}
	fill(d + 1, d + N, INF);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			d[i] = min(d[i], d[i - j] + a[i] - a[i - j + b[j]]);
		}
	}
	printf("%lld\n", d[n]);
}