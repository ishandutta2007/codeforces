#include <bits/stdc++.h>
#include <cstdint>
#include <inttypes.h>
#include <stdint.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

mt19937 rr(random_device{}());

const int inf = 1e9;

pii f(string a, string b)
{
	int x = 0, y = 0;
	for (int i = 0; i < 4; ++i) {
		if (a[i] == b[i]) {
			++x;
			a[i] = b[i] = '?';
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (a[i] == b[j] && a[i] != '?' && b[j] != '?') {
				++y;
				a[i] = b[j] = '?';
			}
		}
	}
	return {x, y};
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	set<string> alive;
	for (int a = 0; a < 10; ++a) {
		for (int b = 0; b < 10; ++b) {
			for (int c = 0; c < 10; ++c) {
				for (int d = 0; d < 10; ++d) {
					string s = "";
					s += char(a + '0');
					s += char(b + '0');
					s += char(c + '0');
					s += char(d + '0');
					alive.insert(s);
				}
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		string s = "";
		for (int j = 0; j < 4; ++j) {
			s += char(rr() % 10 + '0');
		}
		cout << s << "\n";
		cout.flush();
		int x, y;
		cin >> x >> y;
		set<string> next;
		for (auto it : alive) {
			pii p = f(it, s);
			if (p.first == x && p.second == y) {
				next.insert(it);
			}
		}
		alive.swap(next);
	}

	while (sz(alive) > 1) {
		string bestString = "";
		int bestCnt = inf;
		for (int a = 0; a < 10; ++a) {
			for (int b = 0; b < 10; ++b) {
				for (int c = 0; c < 10; ++c) {
					for (int d = 0; d < 10; ++d) {
						string s = "";
						s += char(a + '0');
						s += char(b + '0');
						s += char(c + '0');
						s += char(d + '0');
						map<pii, int> mapa;
						for (auto it : alive) {
							++mapa[f(it, s)];
						}
						int cnt = 0;
						for (auto it : mapa) {
							cnt = max(cnt, it.second);
						}
						if (cnt < bestCnt) {
							bestString = s;
							bestCnt = cnt;
						}
					}
				}
			}
		}
		cout << bestString << "\n";
		cout.flush();
		int x, y;
		cin >> x >> y;
		set<string> next;
		for (auto it : alive) {
			pii p = f(it, bestString);
			if (p.first == x && p.second == y) {
				next.insert(it);
			}
		}
		alive.swap(next);
	}

	cout << *alive.begin() << "\n";
	cout.flush();

}