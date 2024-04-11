//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 33, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int t;
void solve() {
	int a, b;
	cin >> a >> b;
	cout << (a%b==0?"Yes":"No") << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) solve();
}