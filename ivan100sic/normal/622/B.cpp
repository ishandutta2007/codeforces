// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	cin >> s;
	int x;
	cin >> x;
	int t = (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
	t = (t + x) % 1440;

	cout << t/600 << t/60%10 << ':' << t/10%6 << t%10 << '\n';
}