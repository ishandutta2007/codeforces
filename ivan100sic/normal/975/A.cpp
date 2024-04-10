#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	set<set<char>> ss;

	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		set<char> c;
		for (char x : s)
			c.insert(x);
		ss.insert(c);
	}

	cout << ss.size() << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}