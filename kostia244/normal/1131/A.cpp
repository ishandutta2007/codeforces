#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<int, int>
using namespace std;
//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a, b, c, d, ans;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	ans = 2 * (a + b + 2);
	ans -= c;
	ans += d + d + c;
	cout << ans;
}