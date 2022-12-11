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

	int n, m;
	cin >> n >> m;

	set<string> x, y;
	int c = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		x.insert(s);
	}
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (x.count(s)) {
			++c;
			x.erase(s);
		} else {
			y.insert(s);
		}
	}

	int a = sz(x), b = sz(y);
	int player = 0;

	while (true) {
		if (c) {
			--c;
			player ^= 1;
			continue;
		}
		if (player == 0) {
			if (a) {
				--a;
				player ^= 1;
				continue;
			} else {
				break;
			}
		} else {
			if (b) {
				--b;
				player ^= 1;
				continue;
			} else {
				break;
			}
		}
	}

	cout << (player == 1 ? "YES\n" : "NO\n");

}