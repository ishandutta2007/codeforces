#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s, p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (char x : s) {
		if (x == '4')
			p += "322";
		else if (x == '6')
			p += "53";
		else if (x == '8')
			p += "7222";
		else if (x == '9')
			p += "7233";
		else if (x > '1')
			p += x;
	}
	sort(p.begin(), p.end(), greater<char>());
	cout << p << '\n';
}