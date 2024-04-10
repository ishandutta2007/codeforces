#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define vi vector<int>
#define vl vector<ll int>
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define DEBUG fprintf(stderr, "Running on Line %d in Function %s\n", __LINE__, __FUNCTION__)
#pragma GCC optimize("Ofast")
using namespace std;
void yes() {
    cout << "YES\n";
    return;
}
void no() {
    cout << "NO\n";
    return;
}
template <class T>
void out(T temp) {
    cout << temp << endl;
    return;
}
void out(double temp) {
    cout << setprecision(7) << fixed << temp << endl;
    return;
}
void out(long double temp) {
    cout << setprecision(7) << fixed << temp << endl;
    return;
}
// global variables
const int mxN = 1e3 + 1;
int a[mxN][mxN];
bool clear[mxN];
void init() {
    // initialize
    
}
void solve(int case_no) {
	// implementation
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	while (q--) {
		pii cur;
		cin >> cur.ss;
		if (clear[cur.ss]) {
			cout << cur.ss << ' ';
			continue;
		}
		cur.ff = 1;
		bool changed = false;
		while (cur.ff != n + 1) {
			if (a[cur.ff][cur.ss] == 1) {
				a[cur.ff][cur.ss] = 2;
				changed = true;
				cur.ss++;
			} else if (a[cur.ff][cur.ss] == 2) {
				a[cur.ff][cur.ss] = 2;
				cur.ff++;
			} else if (a[cur.ff][cur.ss] == 3) {
				a[cur.ff][cur.ss] = 2;
				changed = true;
				cur.ss--;
			}
		}
		cout << cur.ss << " ";
		if (!changed) clear[cur.ss] = true;
	}
	cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    init();
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
/*

*/