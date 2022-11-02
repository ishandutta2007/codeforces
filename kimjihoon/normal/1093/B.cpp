#include <iostream>
#include <string>
using namespace std;

int r[256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		for (int i = 'a'; i <= 'z'; i++)
			r[i] = 0;
		string s; cin >> s;
		int f = 0;
		for (int i = 0; i < s.length(); i++) {
			if (r[s[i]] == 0) f++;
			r[s[i]]++;
		}
		if (f == 1) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 'a'; i <= 'z'; i++)
			for (int j = 0; j < r[i]; j++)
				cout << (char)i;
		cout << '\n';
	}
	return 0;
}