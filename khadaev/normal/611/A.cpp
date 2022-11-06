#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n;
	string s;
	cin >> n >> s >> s;
	if (s == "week") {
		cout << (n == 5 || n == 6 ? 53 : 52) << '\n';
	} else {
		cout << (n < 30 ? 12 : (n == 30 ? 11 : 7)) << '\n';
	}
}