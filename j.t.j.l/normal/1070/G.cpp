#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

template <class T> using Tree = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool a) {
    return a ? "T" : "F";
}

string to_string(const char* s) {
    return to_string((string) s);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define X first
#define Y second

using ll = long long;
using ld = long double;

const int N = 110;

vector < pair <int, int> > hero[N];
int n, m;
int a[N];
int s[N], h[N];

bool go(int j, int target, vector <int> &ans) {
	if (j == 1 && target == 7) {
		debug("go", ans, j, target);//s[j];
	}
	int d = target > s[j] ? 1 : -1;
	int tmp = h[j];
	for (int i = s[j]; i != target + d; i += d) {
		tmp += a[i];
		if (tmp < 0) return false;
		a[i] = 0;
	}
	ans.push_back(j);
	int who = -1;
	for (int i = 0; i < hero[s[j]].size(); ++i) {
		if (hero[s[j]][i].Y == j) {
			who = i;
		}
	}
	hero[s[j]].erase(hero[s[j]].begin() + who);
	return true;
}

bool solve(vector <int> &a, vector < vector < pair <int, int> > > &who, vector <int> &ans) {
	debug(a, who, ans);
	int n = a.size();
	int nd = 0;
	int last = -1;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += who[i].size();
	}
	debug(a, who, ans, cnt);
	for (int i = 0; i < n; ++i) {
		debug(i, nd);
		if (a[i] < 0) {
			nd -= a[i];
		} else if (a[i] > 0) {
			nd -= a[i];
			maxi(nd, 0);
		}
		if (!who[i].empty()) {
			if (who[i].back().X >= nd) {
				for (int j = i; j > last; --j) {
					for (int k = (int)who[j].size() - 1; k >= 0; --k) {
						ans.push_back(who[j][k].Y);
					}
					//ans.insert(ans.end(), who[j].begin(), who[j].end());
					//ans.insert(ans.end(), who.rbegin(), who.rend());
					cnt -= who[j].size();
				}
				last = i;
				nd = 0;
			} else {
				debug(who[i].back().X, nd);
			}
		}
	}
	return cnt == 0;
}

void run() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", s + i, h + i);
		hero[s[i]].push_back({h[i], i});
	}
	for (int i = 1; i <= n; ++i) {
		sort(hero[i].begin(), hero[i].end());
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	vector <int> ans;
	int place_who = -1;

	for (int i = 1; i <= n; ++i) {
		if (a[i] < 0) {

			for (int j = 0; j < m; ++j) {
				vector <int> a_(n + 1, 0);
				for (int k = 1; k <= n; ++k) a_[k] = a[k];
				vector < pair <int, int> > hero_[N];
				for (int k = 1; k <= n; ++k) hero_[k] = hero[k];

				ans.clear();
				bool ok = 1;
				ok &= go(j, i, ans);

				if (i == 7 && j == 1) {
					debug(ans);
				}
				vector <int> aa(a + 1, a + i + 1);
				reverse(aa.begin(), aa.end());
				vector < vector < pair <int, int> > > who(n + 1, vector < pair <int, int> >());
				for (int j = 1; j <= i; ++j) {
					who[i - j] = hero[j];
				}
				ok &= solve(aa, who, ans);
				aa = vector <int>(a + i, a + n + 1);
				for (int i = 0; i <= n; ++i) who[i].clear();
				for (int j = i + 1; j <= n; ++j) {
					who[j - i] = hero[j];
				}
				ok &= solve(aa, who, ans);
				for (int k = 1; k <= n; ++k) a[k] = a_[k];
				for (int k = 1; k <= n; ++k) hero[k] = hero_[k];

				if (ok) {
					debug("fk", ok);
					place_who = i;
					goto print;
				}
			}
		} else {

			vector <int> aa(a + 1, a + i + 1);
			ans.clear();
			bool ok = 1;
			reverse(aa.begin(), aa.end());
			vector < vector < pair <int, int> > > who(n + 1, vector < pair <int, int> >());
			//vector < vector < pair <int, int> > > who(i, vector < pair <int, int> >());
			for (int j = 1; j <= i; ++j) {
				debug(j, hero[j]);
				who[i - j] = hero[j];
			}
			ok &= solve(aa, who, ans);
			debug(ans);
			aa = vector <int>(a + i, a + n + 1);
			for (int i = 0; i <= n; ++i) who[i].clear();
			for (int j = i + 1; j <= n; ++j) {
				debug(j, hero[j]);
				who[j - i] = hero[j];
			}
			ok &= solve(aa, who, ans);
			debug(ans);

			if (ok) {
				debug("fkk", ok);
				place_who = i;
				goto print;
			}

		}
	}
	print:
	if (place_who != -1) {
		printf("%d\n", place_who);
		for (int i = 0; i < (int)ans.size(); ++i) printf("%d%c", ans[i] + 1, " \n"[i == (int)ans.size() - 1]);
	} else {
		puts("-1");
	}

}

int main() {
	run();
	return 0;
}