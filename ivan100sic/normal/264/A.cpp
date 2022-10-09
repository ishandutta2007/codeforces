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

	list<int> d;
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(), s.end());
	for (char x : s) {
		if (x == 'l')
			d.push_back(n--);
		else
			d.push_front(n--);	
	}
	for (int x : d)
		cout << x << '\n';
}