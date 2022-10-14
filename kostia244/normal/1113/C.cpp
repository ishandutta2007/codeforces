#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
using namespace std;//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, t, x = 0, ans  = 0;
vi cnt[2];

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	cnt[0].resize((1 << 20) + 1, 0);
	cnt[1].resize((1 << 20) + 1, 0);
	cnt[1][0]++;
	for(int i = 0; i < n; i++) {
		cin >> t;
		x ^= t;
		ans += cnt[i%2][x];
		cnt[i%2][x]++;
	}
	cout << ans;
}