#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e5 + 55;
const int mod = 1e9 + 7;
int a[4], b[4];
int win(int x, int y, int u, int v) {
	if (y > u && x > v)
		return 1;
	swap(x, u), swap(y, v);
	if (y > u && x > v)
		return -1;
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 4; i++)
		cin >> a[i] >> b[i];
	int cnter = 0, dr = 0;
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++) {
			int t = win(x ? a[0] : a[1], x ? b[1] : b[0], y ? a[2] : a[3],
					y ? b[3] : b[2]);
			if (t == -1) {
				cnter |= 1 << x;
				dr |= 1 << x;
			}
			if (t == 0) {
				dr |= 1 << x;
			}
		}
	if(cnter==3) return cout << "Team 2", 0;
	if(dr==3) return cout << "Draw", 0;
	cout << "Team 1";
}