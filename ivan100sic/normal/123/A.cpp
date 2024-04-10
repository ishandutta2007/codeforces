#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 100000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	
	if (s.size() <= 3)
		return cout << "YES\n" << s << '\n', 0;

	int n = s.size();

	// kec je izolovan i izolovani su svi prosti brojevi p > n/2 tj 2p > n

	basic_string<int> z = {1}, w;

	for (int p : prosti) {
		if (2*p > n)
			z += p;
	}

	for (int i=1; i<=n; i++) {
		if (z.find({i}) == string::npos)
			w += i;
	}

	map<char, int> mp;
	for (char x : s)
		mp[x]++;

	string q = s;

	char sl = 0;

	for (auto p : mp) {
		if (p.second >= (int)w.size()) {
			// ok moze
			sl = p.first;
			break;
		}
	}

	if (!sl)
		return cout << "NO\n", 0;

	for (int x : w) {
		q[x-1] = sl;
		mp[sl]--;
	}

	for (int x : z) {
		for (auto& p : mp) {
			if (p.second > 0) {
				q[x-1] = p.first;
				p.second--;
				break;
			}
		}
	}

	cout << "YES\n";
	cout << q << '\n';
}