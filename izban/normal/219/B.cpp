#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100;

int n, cans = -1;
ll p, d, ans;

void start(ll p) {
	ll q = p;
	int cc = 0;
	while (q % 10 == 9) {
		cc++;
		q /= 10;
	}
	if (cans < cc) {
		cans = cc;
		ans = p;
	}
}

string tostr(ll x) {
	string res;
	stringstream ss;
	ss << x;
	ss >> res;
	return res;
}

ll toint(string str) {
	ll res;
	stringstream ss;
	ss << str;
	ss >> res;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> p >> d;
	start(p);
	string s = tostr(p);

	s[s.length() - 1] = '9';
	for (int i = (int)s.length() - 2; i >= 0; i--) {
		if (s[i] != '0') {
			s[i] = s[i] - 1;
			if (p - toint(s) <= d) {
				start(toint(s));
			}
		}
		s[i] = '9';
	}

	cout << ans;

	return 0;
}