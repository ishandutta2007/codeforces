#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int main(){
	int n;
	scanf("%d", &n);
	typedef pair<int, long long> PIL;
	typedef pair<int, PIL> PIIL;
	vector<PII> b;
	int mmx = 0;
	for (int i = 1; i <= n; i++) {
		int m;
		scanf("%d", &m);
		vector<int> a(m);
		int mx = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &a[i]);
			mx = max(mx, a[i]);
		}
		b.emplace_back(mx, m);
		mmx = max(mmx, mx);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll del = mmx - b[i].first;
		ans += del * b[i].second;
	}
	printf("%lld\n", ans);
	return 0;
}