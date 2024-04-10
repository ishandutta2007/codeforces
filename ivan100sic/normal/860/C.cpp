#include <bits/stdc++.h>
using namespace std;

int n, e;
set<string> nule_beze, kecevi_beze;
set<pair<string, int>> bezveze;

set<string> svi;
set<string> nule_rupica, kecevi_rupica;

string a[100005], neisk;
int tip[100005];

int parse_int(string s) {
	int x = 0;
	if (s[0] == '0') {
		return -1;
	}
	for (char c : s) {
		if (c < '0' || c > '9') {
			return -1;
		}
		x = 10*x + c - 48;
	}
	if (x < 1 || x > n) {
		return -1;
	}

	return x;
}

vector<string> all_moves;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> tip[i];
		if (tip[i] == 1) {
			e++;
		}
		svi.insert(a[i]);
	}

	cerr << "e: " << e << '\n';

	for (int i=1; i<=n; i++) {
		int x = parse_int(a[i]);
		if (x == -1) {
			bezveze.insert({a[i], tip[i]});
		} else {
			int zeljeni_tip = x <= e ? 1 : 0;
			if (tip[i] != zeljeni_tip) {
				if (zeljeni_tip == 0) {
					nule_beze.insert(a[i]);
				} else {
					kecevi_beze.insert(a[i]);
				}
			}
		}
	}

	for (int i=1; i<=n; i++) {
		if (svi.count(to_string(i)) == 0) {
			if (i > e) {
				nule_rupica.insert(to_string(i));
			} else {
				kecevi_rupica.insert(to_string(i));
				cerr << "kec rupica " << i << '\n';
			}
		}
	}

	if (bezveze.size() == 0 && nule_beze.size() > 0) {

		// moracu da nadjem temp ime
		for (int i=n+1;; i++) {
			if (svi.count(to_string(i)) == 0) {
				neisk = to_string(i);
				break;
			}
		}

		// uzmi jednog iz nula koje beze i preimenuj ga u temp
		string s0 = *nule_beze.begin();
		all_moves.push_back(s0 + ' ' + neisk);
		nule_beze.erase(s0);
		nule_rupica.insert(s0);
		bezveze.insert({neisk, 1});
	}

	{
		// nadji slobodno

		while (nule_beze.size() > 0 || kecevi_beze.size() > 0) {
			if (nule_beze.size() > 0 && kecevi_rupica.size() > 0) {
				auto s1 = *nule_beze.begin();
				auto s2 = *kecevi_rupica.begin();

				all_moves.push_back(s1 + ' ' + s2);
				nule_beze.erase(s1);
				kecevi_rupica.erase(s2);

				nule_rupica.insert(s1);
			} else {
				auto s1 = *kecevi_beze.begin();
				auto s2 = *nule_rupica.begin();

				all_moves.push_back(s1 + ' ' + s2);
				kecevi_beze.erase(s1);
				nule_rupica.erase(s2);

				kecevi_rupica.insert(s1);
			}
		}

		// izubacuj ove bezeveze
		for (auto p : bezveze) {
			if (p.second == 0) {
				auto s2 = *nule_rupica.begin();
				all_moves.push_back(p.first + ' ' + s2);
				nule_rupica.erase(s2);
			} else {
				auto s2 = *kecevi_rupica.begin();
				all_moves.push_back(p.first + ' ' + s2);
				kecevi_rupica.erase(s2);
			}
		}
	}

	cout << all_moves.size() << '\n';
	for (auto s : all_moves) {
		cout << "move " << s << '\n';
	}
}