#include<bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxn = 2e5 + 5;
int64_t h[maxn];
int n, k, p[maxn], q[maxn];
char str[maxn];
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		h[i] = rng();
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++)
		cin >> q[i];

	char c = 'a';
	int h_p, h_q;
	h_p = h_q = 0;
	for (int i = 1; i <= n; i++) {
		h_p^=h[p[i]];
		h_q^=h[q[i]];
		str[p[i]] = c;
		if(i != n && c!='z' && h_p == h_q) {
			c++;
		}
	}

	if(c-'a'+1 < k)
		return cout << "NO", 0;
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
		cout << str[i];
	return 0;
}