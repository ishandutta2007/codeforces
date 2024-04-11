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
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
#endif
}
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;
const int p = 37;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int b[1000005];
string s;
int main() {
	doin();
	cin >> s;
	int i = 0, j = -1;
	b[0] = -1;
	while(i < s.size()) {
		while(j != -1 && s[i] != s[j]) j = b[j];
		i++;
		j++;
		b[i] = j;
	}
	i = b[s.size()];
	while(i != 0) {
		for(j = 0; j < s.size(); j++) {
			if(b[j] == i)
				return cout << s.substr(0, i), 0;
		}
		i = b[i];
	}
	cout << "Just a legend";
	return 0;
}