#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {
	string cd;
	cin >> cd;
	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		if (s[0] == cd[0] || s[1] == cd[1]) {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}