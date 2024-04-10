 #include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// #include <algorithm>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 3e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
//const int pp = 41;
const int inf = 2e9;
const ll llinf = 1e18;

vector<ll> solve() {
	// ifstream cin("input.txt");

	int n, w;
	cin >> n >> w;

	vector<int> l(n);

	vector<ll> ans(w + 1, 0);
	vector<vector<int> > a(n);

	for (int i = 0; i < n; i++) {
		cin >> l[i];
		a[i].resize(l[i]);
		
		vector<pii> e;
		for (int j = 0; j < l[i]; j++) {
			cin >> a[i][j];
			e.pb(mp(a[i][j], j));
		}

		sort(all(e));
		reverse(all(e));

		set<pii> rng;
		for (const auto& [val, pos] : e) {
			int left = pos, r = pos + w - l[i];
			if (val < 0) {

				r = min(r, l[i] - 1);
				left = max(left, w - l[i]);
				
			}

			auto it = rng.upper_bound(mp(left, inf));
			if (it != rng.begin()) {
				it--;
				left = max(left, it->s + 1);
				it++;
			}
			if (it != rng.end()) {
				r = min(r, it->f - 1);
			}

			if (left > r) continue;
			if (val >= 0) {
				ans[left] += val;
				ans[r + 1] -= val;

				bool ns = true;

				if (it != rng.begin()) {
					it--;
					if (left == it->s + 1) {
						// it->s = r;
						
						pii nw = *it;
						nw.s = r;

						rng.erase(it);
						rng.insert(nw);
						it = rng.find(nw);

						ns = false;
					}
					it++;
				}

				if (it != rng.end()) {
					if (r == it->f - 1) {
						if (ns == false) {
							int fn = it->s;
							pii o1 = *it;

							it--;
							pii nw = {it->f, fn};
							pii o2 = *it;

							rng.erase(o1);
							rng.erase(o2);
							// it = rng.insert(nw);
							rng.insert(nw);
						} else {

							pii nw = *it;
							nw.f = left;

							rng.erase(it);
							// it = rng.insert(nw);
							rng.insert(nw);
							ns = false;
						}
					}
				}

				if (ns) rng.insert({left, r});
			} else {
				// if (val == -6) {
				// 	cout << left << ' ' << r << endl;
				// 	for (auto e : rng) {
				// 		cout << e.f << ' ' << e.s << endl;
				// 	}

				// }
				// cout << val << ' ' << left << ' ' << r << endl;
			
				if (left <= r) {
					ans[left] += val;
					ans[r + 1] -= val;

					auto it = rng.upper_bound(mp(left, inf));
					bool ns = true;
					
					if (it != rng.begin()) {
						it--;
						if (left == it->s + 1) {
							// it->s = r;
							
							pii nw = *it;
							nw.s = r;

							rng.erase(it);
							// it = rng.insert(nw);
							rng.insert(nw);
							it = rng.find(nw);

							ns = false;
						}
						it++;
					}

					if (it != rng.end()) {
						if (r == it->f - 1) {
							if (ns == false) {
								int fn = it->s;
								pii o1 = *it;

								it--;
								pii nw = {it->f, fn};
								pii o2 = *it;

								rng.erase(o1);
								rng.erase(o2);
								// it = rng.insert(nw);
								rng.insert(nw);
							} else {
								pii nw = *it;
								nw.f = left;

								rng.erase(it);
								rng.insert(nw);
								// it = rng.insert(nw);
								ns = false;
							}
						}
					}

					if (ns) rng.insert({left, r});
				}
			}
		}
	}   

	for (int i = 0; i < w; i++) {
		if (i) ans[i] += ans[i - 1];
		// cout << ans[i] << ' ';
	} 
	ans.pop_back();
	return ans;
	// cout << endl;
}

void gen() {
	ofstream cout("input.txt");
	int n = 3, w = rand() % 20 + 1;
	cout << n << ' ' << w << endl;
	for (int i = 0; i < n; i++) {
		int l = rand() % w + 1;
		cout << l << ' ';
		for (int i = 0; i < l; i++) {
			cout << rand() % 101 - 50 << ' ';
		}
		cout << endl;
	}
}

vector<ll> brute() {
	ifstream cin("input.txt");

	int n, w;
	cin >> n >> w;

	vector<int> l(n);

	vector<ll> ans(w, 0);
	vector<vector<int> > a(n);

	for (int i = 0; i < n; i++) {
		cin >> l[i];
		a[i].resize(l[i]);
		
		for (int j = 0; j < l[i]; j++) {
			cin >> a[i][j];
		}

		vector<ll> kek(w, -llinf);
		for (int sd = 0; l[i]+ sd <= w; sd++) {
			for (int j = 0; j < w; j++) {
				// sd, sd + l[i] - 1
				if (j < sd) {
					upmax(kek[j], 0);
				} else if (j >= sd + l[i]) {
					upmax(kek[j], 0);
				} else {
					upmax(kek[j], a[i][j - sd]);
				}
			}
		}
		for (int i = 0; i < w; i++) {
			ans[i] += kek[i];
			assert(kek[i] != -llinf);
		}
	}
	return ans;
}

int n, cc;
int res[1001][1001];

bool check() {
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x = 0, x2 = 0;
		for (int j = 0; j < n; j++) {
			x ^= res[i][j];
			x2 ^= res[j][i];
		}
		s.insert(x);
		s.insert(x2);
		// cout << x << ' ' << x2 << endl;
	}
	// cout <<
	// for (auto e : s) {
	// 	cout << e << ' ';
	// }
	return s.size() == 1;
}

int main() {
	srand(time(0));
    ios_base::sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);
	// for (auto e : solve()) {
	// 	cout << e << ' ';
	// }

    n = 4, cc = 0;
    cin >> n;

    for (int i = 0; i < n / 4; i++)
    	for (int j = 0; j < n / 4; j++) {
    		for (int x = i * 4; x < i * 4 + 4; x++) {
    			if (x % 2 == 0) {
    				for (int y = j * 4; y < j * 4 + 4; y++) {
    					res[x][y] = cc++;
    				}
    			} else {
    				for (int y = j * 4 + 3; y >= j * 4; y--) {
    					res[x][y] = cc++;
    				}
    			}
    		}
    	}
    	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cout << res[i][j] << " \n"[j == n - 1];
    // if (check()) {
    	// cout << "ok";
    // }
	// // solve();
	// return 0;
	// for (int i = 0; i < 1000; i++) {
	// 	gen();
	// 	if (auto a = solve(), b = brute(); a != b) {
	// 		cout << "kek";
	// 		for (auto e : a)
	// 			cout << e << ' ';
	// 		exit(0);
	// 	}
	// }

}