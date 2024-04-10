#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s[205];
char q[205];

void probaj(string r) {
	vector<pair<string, char>> v;
	for (int i=1; i<(int)r.size(); i++) {
		v.push_back({r.substr(0, i), 'P'});
		v.push_back({r.substr(r.size() - i), 'S'});
	}
	for (int i=0; i<2*n-2; i++) {
		// probaj da nadjes
		auto it = find_if(v.begin(), v.end(), [&](auto x) { return x.first == s[i]; });
		if (it == v.end())
			return;
		q[i] = it->second;
		v.erase(it);
	}
	for (int i=0; i<2*n-2; i++)
		cout << q[i];
	cout << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<2*n-2; i++)
		cin >> s[i];

	int j = -1, k = -1;
	for (int i=0; i<2*n-2; i++) {
		if (j == -1 || s[i].size() > s[j].size()) {
			k = j;
			j = i;
		} else if (k == -1 || s[i].size() > s[k].size()) {
			k = i;
		}
	}
	string p = s[j];
	string q = s[k];

	probaj(p + q.back());
	probaj(q + p.back());
}