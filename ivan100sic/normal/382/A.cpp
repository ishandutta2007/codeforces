#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s, p;
	cin >> s >> p;
	int i = find(s.begin(), s.end(), '|') - s.begin();
	string s1 = s.substr(0, i);
	string s2 = s.substr(i+1);

	for (char x : p)
		(s1.size() < s2.size() ? s1 : s2) += x;
	if (s1.size() != s2.size())
		cout << "Impossible\n";
	else
		cout << s1 << "|" << s2 << '\n';
}