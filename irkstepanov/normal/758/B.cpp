#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	map<char, int> m;

	for (int i = 0; i < sz(s); ++i) {
		if (s[i] != '!' && !m.count(s[i])) {
			int cnt = 0;
			for (int j = 0; j < sz(s); ++j) {
				if (j % 4 == i % 4 && s[j] == '!') {
					++cnt;
				}
			}
			m[s[i]] = cnt;
		}
	}

	cout << m['R'] << " " << m['B'] << " " << m['Y'] << " " << m['G'] << "\n";

}