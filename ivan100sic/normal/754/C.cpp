#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

string dummy;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<string> names(n);
		for (string& s : names) {
			cin >> s;
		}

		int m;
		cin >> m;
		getline(cin, dummy);
		vector<vector<bool>> mentions(m, vector<bool>(n, false));
		vector<int> author(m, -1);
		vector<string> lnorig(m);

		for (int i=0; i<m; i++) {
			string ln;
			getline(cin, ln);

			string auth = ln.substr(0, ln.find(":"));
			ln = ln.substr(ln.find(":") + 1, string::npos);

			if (auth != "?") {
				author[i] = find(names.begin(), names.end(), auth) - names.begin();
			}

			lnorig[i] = ln;

			ln = string(" ") + ln + string(" ");

			for (int j=0; j<n; j++) {
				const string& name = names[j];
				// za ovo ime proverimo da li se javlja u cetu
				// proverimo da li je na prvom mestu
				int L = name.size();

				bool ok = false;

				for (int p=1; p+L < ln.size(); p++) {
					if (!isalnum(ln[p-1]) && !isalnum(ln[p+L]) &&
						ln.substr(p, L) == name)
					{
						ok = true;
						break;
					}
				}

				if (ok) {
					mentions[i][j] = true;
				}
			}
		}

		vector<vector<pair<int, int>>> pos(m);

		if (author[0] == -1) {
			for (int j=0; j<n; j++) {
				if (!mentions[0][j]) {
					pos[0].push_back({j, -1});
				}
			}
		} else {
			pos[0].push_back({author[0], -1});
		}

		for (int j=1; j<m; j++) {
			if (pos[j-1].size() == 0) {
				continue;
			} else {
				if (author[j] != -1) {
					/*
					if (pos[j-1].size() == 1) {
						pos[j].push_back({author[j], pos[j-1][0].first});
					} else if () {
						pos[j].push_back({author[j], pos[j-1][1].first});
					} else {
						continue;
					}
					*/
					if (pos[j-1].size() == 1) {
						if (pos[j-1][0].first == author[j]) {
							continue;
						} else {
							pos[j].push_back({author[j], pos[j-1][0].first});
						}
					} else {
						int a1 = pos[j-1][0].first;
						int a2 = pos[j-1][1].first;

						if (a1 != author[j]) {
							pos[j].push_back({author[j], a1});
						} else {
							// a2 != author
							pos[j].push_back({author[j], a2});
						}
					}
				} else {
					if (pos[j-1].size() >= 2) {
						// svako ko nije mentionovan
						for (int k=0; k<n; k++) {
							if (!mentions[j][k]) {
								int preth = pos[j-1][0].first;
								if (preth == k) {
									preth = pos[j-1][1].first;
								}
								pos[j].push_back({k, preth});
							}
						}
					} else {
						// svako ko nije mentionovan i nije prethodni
						for (int k=0; k<n; k++) {
							if (!mentions[j][k]) {
								int preth = pos[j-1][0].first;
								if (preth != k) {
									pos[j].push_back({k, preth});
								}
							}
						}
					}
				}
			}
		}

		if (pos[m-1].size() == 0) {
			cout << "Impossible\n";
		} else {
			int x = pos[m-1][0].first;
			int j = m-1;

			vector<string> to_print;

			while (x != -1) {
				to_print.push_back(names[x] + ":" + lnorig[j] + '\n');

				for (int k=0; k<pos[j].size(); k++) {
					if (pos[j][k].first == x) {
						x = pos[j][k].second;
						j--;
						break;
					}
				}
			}

			
			for (int i=to_print.size()-1; i>=0; i--) {
				cout << to_print[i];
			}
		}
	}

}