#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int n, l;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<string, pair<vector<int>, vector<int>>> ab;
	map<string, vector<int>> aba;

	cin >> n >> l;

	for (int i=0; i<n; i++) {
		string s, r;
		int v;
		cin >> s >> v;

		r = s;
		reverse(r.begin(), r.end());

		if (r != s) {
			auto is = ab.find(s);
			auto ir = ab.find(r);

			if (is == ab.end() && ir == ab.end()) {
				ab[s].first.push_back(v);
			} else if (is == ab.end()) {
				ab[r].second.push_back(v);
			} else {
				ab[s].first.push_back(v);
			}
		} else {
			aba[s].push_back(v);
		}
	}

	int sol = 0;
	
	for (auto p : ab) {
		int w = min(p.second.first.size(), p.second.second.size());

		sort(p.second.first.begin(), p.second.first.end());
		reverse(p.second.first.begin(), p.second.first.end());

		sort(p.second.second.begin(), p.second.second.end());
		reverse(p.second.second.begin(), p.second.second.end());

		for (int i=0; i<w; i++) {
			int t = p.second.first[i] + p.second.second[i];
			if (t < 0) {
				break;
			} else {
				sol += t;
			}
		}
	}

	int solo = 0;
	vector<pair<int, int>> sus;

	for (auto p : aba) {
		sort(p.second.begin(), p.second.end());
		reverse(p.second.begin(), p.second.end());

		int i = 0;
		while (i+1 < p.second.size()) {
			if (p.second[i] >= 0 && p.second[i+1] >= 0) {
				sol += p.second[i] + p.second[i+1];
			} else if (p.second[i] >= 0 && p.second[i+1] < 0) {
				sus.push_back({p.second[i], p.second[i+1]});
				i = 100000000;
				break;
			} else {
				i = 100000000;
				break;
			}

			i += 2;
		}

		if (i < p.second.size()) {
			solo = max(solo, p.second[i]);
		}
	}

	int addon = 0;

	// uzimam solo i sve zbirove vece od 0
	int zbir0 = 0;
	for (auto p : sus) {
		zbir0 += max(0, p.first + p.second);
	}

	addon = max(addon, zbir0 + solo);

	// uzimam sve zbirove vece od 0 osim trenutnog gde uzimam veceg kao solo
	for (auto p : sus) {
		addon = max(addon, zbir0 - max(0, p.first + p.second) + p.first);
	}

	cout << sol + addon;
}