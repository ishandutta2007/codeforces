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
#define mod 1234567891ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//		freopen("in", "r", stdin);
//		freopen("out", "w", stdout);
#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n;
vi a;
multiset<int> b;

int add(int a, int b) {
	int c = a+b;
	if(c >= n)
		c-=n;
	return c;
}

pair<int, multiset<int>::iterator> trymax(int a) {
	multiset<int>::iterator i = b.lower_bound(n-a), j;
	j = i;
	j++;
	if(i == b.end())
		i--;
	if(j == b.end() || add(a, *i) < add(a, *j))
		return {add(a, *i), i};
	return {add(a, *j), j};

}
pair<int, multiset<int>::iterator> trymin(int a) {
	multiset<int>::iterator i = b.begin();
//	cout << *i << " " << a << " " << add(a, *i) << "\n";
	return {add(a, *i), i};
}

int main() {
	doin();
	cin >> n;
	getv(a, n);
	for(int i = 0, t; i < n; i++)
		cin >> t, b.insert(t);
	multiset<int>::iterator it1, it2;
	int a1, a2;
	for(auto i : a) {
		tie(a1, it1) = trymax(i);
		tie(a2, it2) = trymin(i);
//		cout <<a1 << " " << a2 << "\n";
		if(a1 < a2)
			cout << a1 << " ", b.erase(it1);
		else
			cout << a2 << " ", b.erase(it2);
	}
}