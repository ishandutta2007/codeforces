#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s, t;
	cin >> s >> t;
	reverse(t.begin(), t.end());
	cout << (s == t ? "YES" : "NO");
	
}