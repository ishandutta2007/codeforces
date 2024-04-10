#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;

const int N = 200009;
long long md = 1000000007;
long long rs[N], ar[N], ans = 1;
vector<int> pr;
bool pb[N];
int cp[N][109], mn[N], vc[N];
map<int, int> mp[N];
pair<int, int> qr[N];

long long fp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k & 1) s = (s * n) % md;
		k /= 2; n = (n * n) % md;
	}
	return s;
}

void up(int pi, int w, int t)
{
	for (int i = 0; i < pr.size(); i++) {
		int p = 0;
		while (w % pr[i] == 0) {
			w /= pr[i];
			p++;
		}
		if (!p) continue;
		cp[pi][i] += p * t;
		if (t < 0 && cp[pi][i] < mn[pr[i]]) {
			ans = (ans * fp(rs[pr[i]], mn[pr[i]] - cp[pi][i])) % md;
			mn[pr[i]] = cp[pi][i];
		}
	}
	if (w > 1) {
		mp[pi][w] += t;
		if (t < 0) {
			int tm = mp[pi][w];
			if (tm < mn[w]) {
				ans = (ans * rs[w]) % md;
				mn[w] = tm;
			}
		}
		else if (mp[pi][w] == 1)
			vc[w]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 2; i <= N; i++) {
		if (pb[i]) continue;
		for (int j = i; j <= N; j += i)
			pb[j] = true;
		if (1LL * i * i <= 1LL * N) pr.push_back(i);
		rs[i] = fp(i, md - 2);
	}
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		up(i, a, 1);
	}
	for (int i = 0; i < q; i++) {
		cin >> qr[i].first >> qr[i].second;
		up(qr[i].first, qr[i].second, 1);
	}
	for (int i = 0; i < pr.size(); i++) {
		mn[pr[i]] = cp[1][i];
		for (int j = 2; j <= n; j++)
			mn[pr[i]] = min(mn[pr[i]], cp[j][i]);
		ans = (ans * fp(pr[i], mn[pr[i]])) % md;
	}
	for (int i = 2; i <= N; i++) {
		if (vc[i] < n) continue;
		mn[i] = mp[1][i];
		for (int j = 2; j <= n; j++)
			mn[i] = min(mn[i], mp[j][i]);
		ans = (ans * fp(i, mn[i])) % md;
	}
	for (int i = q - 1; i >= 0; i--) {
		ar[i] = ans;
		up(qr[i].first, qr[i].second, -1);
	}
	for (int i = 0; i < q; i++) {
		cout << ar[i] << '\n';
	}
	return 0;
}