#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int tot(string s) {
	return stoi(s.substr(0, 2))*60 + stoi(s.substr(3));
}

void p2(int x) {
	cout << (x < 10 ? "0" : "") << x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	cin >> a >> b;
	int ta = tot(a);
	int tb = tot(b);
	int tc = (ta + tb) / 2;
	p2(tc / 60);
	cout << ":";
	p2(tc % 60);
	cout << "\n";
}