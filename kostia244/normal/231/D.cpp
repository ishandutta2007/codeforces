#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mod 998244353ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
}
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <int> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll ans, x, y, z, xs, ys, zs, a[6];
int main() {
	doin();
	cin >> x >> y >> z;
	cin >> xs >> ys >> zs;
	for(int i = 0; i < 6; i++) {
        cin >> a[i];
	}
    if(y < 0)
        ans += a[0];
    else if(y > ys)
        ans += a[1];
    if(z < 0)
        ans += a[2];
    else if(z > zs)
        ans += a[3];
    if(x < 0)
        ans += a[4];
    else if(x > xs)
        ans += a[5];
    cout << ans;
}