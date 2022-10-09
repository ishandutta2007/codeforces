#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;


int a[200005], ao[200005], n, m;
map<int, vector<int>> cc;

vector<int> mv[2];
vector<int> dupli[2];
int c[2];

int gv(vector<int>& v) {
	int r = *v.rbegin();
	v.pop_back();
	//cerr << "giving " << r << '\n';
	return r;
}

int main() {
	cin >> n >> m;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		ao[i] = a[i];
		c[a[i] % 2]++;
		cc[a[i]].push_back(i);
	}
	
	for (auto p : cc) {
		int ps = p.second.size();
		for (int i=1; i<ps; i++) {
			dupli[p.first % 2].push_back(p.second[i]);
		}
	}

	for (int i=1; i<=min(m, 4*n); i++) {
		if (cc[i].size() == 0) {
			mv[i % 2].push_back(i);	
		}		
	}

	// skloni duplikate, izaberi kartu za zamenu koja
	// vise fali
	vector<int> duplii;
	for (int i=0; i<2; i++) {
		for (int x : dupli[i]) {
			duplii.push_back(x);
		}
	}

	for (int x : duplii) {
		if (c[0] > c[1]) {
			// probaj odd
			if (mv[1].size()) {
				c[a[x] % 2]--;
				a[x] = gv(mv[1]);
				c[a[x] % 2]++;
				continue;
			}
			// jebiga uzmi even
			if (mv[0].size()) {
				c[a[x] % 2]--;
				a[x] = gv(mv[0]);
				c[a[x] % 2]++;
				continue;
			}
			// rip
			cout << -1;
			return 0;
		} else if (c[0] < c[1]) {
			// reverse
			if (mv[0].size()) {
				c[a[x] % 2]--;
				a[x] = gv(mv[0]);
				c[a[x] % 2]++;
				continue;
			}

			if (mv[1].size()) {
				c[a[x] % 2]--;
				a[x] = gv(mv[1]);
				c[a[x] % 2]++;
				continue;
			}
			// rip
			cout << -1;
			return 0;
		} else {
			// zameni sa istom ako mozes
			if (a[x] % 2 == 1) {
				if (mv[1].size()) {
					c[a[x] % 2]--;
					a[x] = gv(mv[1]);
					c[a[x] % 2]++;
					continue;
				}
				if (mv[0].size()) {
					c[a[x] % 2]--;
					a[x] = gv(mv[0]);
					c[a[x] % 2]++;
					continue;
				}
				// rip
				cout << -1;
				return 0;
			} else {
				if (mv[0].size()) {
					c[a[x] % 2]--;
					a[x] = gv(mv[0]);
					c[a[x] % 2]++;
					continue;
				}

				if (mv[1].size()) {
					c[a[x] % 2]--;
					a[x] = gv(mv[1]);
					c[a[x] % 2]++;
					continue;
				}
				// rip
				cout << -1;
				return 0;
			}
			
		}
	}

	//cerr << "we made it\n";

	for (auto p : cc) {
		if (p.second.size() == 0) continue;
		int x = p.second[0];
		if (c[0] > c[1]) {
			// probaj odd
			if (a[x] % 2 == 1) {
				// nema potrebe
				continue;
			}
			if (mv[1].size()) {
				c[a[x] % 2]--;
				a[x] = gv(mv[1]);
				c[a[x] % 2]++;
				continue;
			}
			// rip
			cout << -1;
			return 0;
		} else if (c[0] < c[1]) {
			// reverse
			if (a[x] % 2 == 0) {
				continue;
			}
			if (mv[0].size()) {
				c[a[x] % 2]--;
				a[x] = gv(mv[0]);
				c[a[x] % 2]++;
				continue;
			}
			// rip
			cout << -1;
			return 0;
		} else {
			break;
		}
	}

	if (c[0] != c[1]) {
		cout << -1;
		return 0;
	}

	{
		int df = 0;
		for (int i=1; i<=n; i++) {
			if (a[i] != ao[i]) {
				df++;
			}
		}
		cout << df << '\n';
		for (int i=1; i<=n; i++) {
			cout << a[i] << ' ';
		}
	}
}