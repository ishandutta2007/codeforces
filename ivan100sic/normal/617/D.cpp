#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool ch(int a, int b, int c, int d, int e, int f) {
	return (a == c && b == f) || (a == e && b == d);
}

bool g(int a, int b, int c, int d, int e, int f) {
	return c == e && 0ll + abs(b-d) + abs(b-f) > abs(d-f);
}

bool gg(int a, int b, int c, int d, int e, int f) {
	bool r = false;
	r |= g(a, b, c, d, e, f);
	r |= g(c, d, e, f, a, b);
	r |= g(e, f, a, b, c, d);
	swap(a, b);
	swap(c, d);
	swap(e, f);
	r |= g(a, b, c, d, e, f);
	r |= g(c, d, e, f, a, b);
	r |= g(e, f, a, b, c, d);
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int p = set<int>({a, c, e}).size();
	int q = set<int>({b, d, f}).size();

	if (p == 1 || q == 1)
		cout << "1\n";
	else if (ch(a, b, c, d, e, f) || ch(c, d, e, f, a, b) || ch(e, f, a, b, c, d))
		cout << "2\n";
	else if (gg(a, b, c, d, e, f))
		cout << "2\n";
	else
		cout << "3\n";
}