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
//	freopen("in", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, o = 0, cl = 0, op = 0, a = 0, d = 0;
string s;

int main() {
	doin();
	cin >> n;
	cin >> s;
	if(n&1)
		return cout << ":(", 0;
	for(auto& i : s) {
		if(i == '?')
			a++;
		else if(i == '(')
			cl--;
		else
			cl++;
		if(cl-a > 0)
			return cout << ":(", 0;
	}
	for(int ii = 0; ii < n; ii++) {
		char i = s[ii];
		if(i == '(')
			o++;
		else if(i == ')')
			o--;
		else {
			d++;
			if(d<=(a+cl)/2)
				s[ii] = '(', o++;
			else
				s[ii] = ')', o--;
		}
		if(o == 0 && ii+1 != n)
			return cout << ":(", 0;
	}
	if(o != 0)
		return cout << ":(", 0;
	cout << s;
	return 0;
}