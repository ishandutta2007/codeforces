//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e2 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a;
	cout << 2*a - 1 << " " << 2 << '\n';
	cout << "1 2";
}