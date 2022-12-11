#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int a, b, c, d;
    int n;
    cin >> a >> b >> c >> d >> n;

    vector<vector<char> > ans(max(b, d), vector<char>(a + c, '.'));
    for (int i = 0; i < b; ++i) {
    	for (int j = 0; j < a; ++j) {
    		ans[i][j] = '?';
    	}
    }
    for (int i = 0; i < d; ++i) {
    	for (int j = 0; j < c; ++j) {
    		ans[i][j + a] = '?';
    	}
    }

    int dir;
    if (b > d) {
    	if (d % 2 == 0) {
    		dir = 1;
    	} else {
    		dir = -1;
    	}
    } else {
    	if (b % 2 == 1) {
    		dir = 1;
    	} else {
    		dir = -1;
    	}
    }

    vector<pii> lst;
    for (int i = 0; i < max(b, d); ++i) {
    	if (dir == 1) {
    		for (int j = 0; j < a + c; ++j) {
    			if (ans[i][j] != '.') {
    				lst.pb({i, j});
    			}
    		}
    	} else {
    		for (int j = a + c - 1; j >= 0; --j) {
    			if (ans[i][j] != '.') {
    				lst.pb({i, j});
    			}
    		}
    	}
    	dir *= (-1);
    }

    char letter = 'a';
    int pos = 0;
    while (n--) {
    	int x;
    	cin >> x;
    	while (x--) {
    		int i = lst[pos].first, j = lst[pos].second;
    		ans[i][j] = letter;
    		++pos;
    	}
    	++letter;
    }

    cout << "YES\n";
    for (int i = 0; i < max(b, d); ++i) {
    	for (int j = 0; j < a + c; ++j) {
    		cout << ans[i][j];
    	}
    	cout << "\n";
    }

}