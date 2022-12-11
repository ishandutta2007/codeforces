#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct data
{
	string x, y;
};

int n;
vector<data> v;
bool ok;
vector<int> res;
vector<int> used;
queue<int> q;

void f(int pos, int val)
{
	//cout << "TRY " << pos << " " << val << "\n";
	res[pos] = val;
	q.push(pos);
	used.pb(pos);

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (res[t] == 0) {
			for (int j = 0; j < n; ++j) {
				if (j == t) {
					continue;
				}
				if (v[j].x == v[t].x) {
					ok = false;
					break;
				}
				if (v[j].x.substr(0, 2) + v[j].y == v[t].x) {
					if (res[j] == 1) {
						ok = false;
						break;
					} else if (res[j] == -1) {
						res[j] = 0;
						q.push(j);
						used.pb(j);
					}
				}
			}
		} else {
			for (int j = 0; j < n; ++j) {
				if (j == t) {
					continue;
				}
				if (v[j].x == v[t].x) {
					if (res[j] == 0) {
						ok = false;
						break;
					} else if (res[j] == -1) {
						res[j] = 1;
						q.push(j);
						used.pb(j);
					}
				}
				if (v[j].x == v[t].x.substr(0, 2) + v[t].y) {
					if (res[j] == 0) {
						ok = false;
						break;
					} else if (res[j] == -1) {
						res[j] = 1;
						q.push(j);
						used.pb(j);
					}
				}
				if (v[j].x.substr(0, 2) + v[j].y == v[t].x.substr(0, 2) + v[t].y) {
					if (res[j] == 1) {
						ok = false;
						break;
					} else if (res[j] == -1) {
						res[j] = 0;
						q.push(j);
						used.pb(j);
					}
				}
			}
		}
		if (!ok) {
			break;
		}
	}

	if (!ok) {
		for (int x : used) {
			res[x] = -1;
		}
	} /*else {
		for (int t : used) {
			for (int j = 0; j < n; ++j) {
				if (t == j || res[j] == -1) {
					continue;
				}
				if (res[t] == 0) {
					if (res[j] == 0 && v[t].x == v[j].x) {
						assert(false);
					}
					if (res[j] == 1 && v[j].x.substr(0, 2) + v[j].y == v[t].x) {
						assert(false);
					}
					if (res[j] == 1 && v[j].x == v[t].x) {
						assert(false);
					}
				} else {
					if (res[j] == 0 && v[j].x == v[t].x.substr(0, 2) + v[t].y) {
						assert(false);
					}
					if (res[j] == 0 && v[j].x == v[t].x) {
						assert(false);
					}
					if (res[j] == 1 && v[j].x.substr(0, 2) + v[j].y == v[t].x.substr(0, 2) + v[t].y) {
						assert(false);
					}
				}
			}
		}
	}*/

	while (!q.empty()) {
		q.pop();
	}
	used.clear();
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; ++i) {
		string x, y;
		cin >> x >> y;
		v[i].x = x.substr(0, 3);
		v[i].y = y.substr(0, 1);
	}

	res.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (res[i] == -1) {
			ok = true;
			f(i, 0);
			if (!ok) {
				ok = true;
				f(i, 1);
				if (!ok) {
					cout << "NO\n";
					return 0;
				}
			}
		}
	}

	/*for (int t = 0; t < n; ++t) {
		for (int j = 0; j < n; ++j) {
			if (j == t) {
				continue;
			}
		}
	}*/

	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		if (res[i] == 0) {
			cout << v[i].x << "\n";
		} else {
			cout << v[i].x.substr(0, 2) + v[i].y << "\n";
		}
	}

}