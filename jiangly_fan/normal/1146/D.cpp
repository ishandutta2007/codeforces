#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int maxn = 240000;
void no(){
	cout << ":(";
	exit(0);
}
LL d[maxn], s[maxn];
priority_queue<PII, vector<PII>, greater<PII>> q;
int main(){
	ios::sync_with_stdio(false);
	LL m, a, b;
	cin >> m >> a >> b;
	fill(d, d + maxn, 1e18);
	q.push(make_pair(d[0] = 0, 0));
	while(not q.empty()){
		int u = q.top().second, w = q.top().first;
		q.pop(); 
		if(w > d[u]) continue;
		if(u + a < maxn and d[u + a] > max(d[u], u + a)) q.push(make_pair(d[u + a] = max(d[u], u + a), u + a));
		if(u >= b and d[u - b] > d[u]) q.push(make_pair(d[u - b] = d[u], u - b));
	}
	for(int i = 0; i < maxn; i += 1) if(d[i] < maxn) s[d[i]] += 1;
	for(int i = 1; i < maxn; i += 1) s[i] += s[i - 1];
	//for(int i = 0; i < 10; i += 1) cout << i << " " << s[i] << endl;
	LL x = __gcd(a, b), ans = 0;
	for(int i = 0; i < a + b and i <= m; i += 1) ans += s[i];
	if(m >= a + b){
		LL mm = m / x * x;
		ans += x * ((a + b) / x + (mm - x) / x + 2) * ((mm - a - b - x) / x + 1) / 2;
		ans += (m % x + 1) * (m / x + 1);
	}
	//for(int i = 0; i <= m; i += 1) ans += s[i];
	cout << ans;
}