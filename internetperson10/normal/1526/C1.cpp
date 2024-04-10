#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> v, p;
priority_queue<ll> pq;

int main() {
	int n;
	cin >> n;
	int ans = n;
	v.resize(n);
	p.resize(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) {
		if(i == 0) p[i] = v[i];
		else p[i] = v[i] + p[i-1];
	}
	ll x = 0;
	for(int i = 0; i < n; i++) {
		if(v[i] < 0) pq.push(-v[i]);
		while(x + p[i] < 0 && pq.size()) {
			x += pq.top(); pq.pop(); ans--;
		}
	}
	cout << ans << '\n';
}