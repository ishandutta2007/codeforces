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

pii f(string x, string y) {
	int a = 0;
	for (int i = 0; i < sz(x); ++i) {
		if (x[i] == y[i]) {
			++a;
		}
	}
	int b = 0;
	for (int i = 0; i < sz(y); ++i) {
		for (int j = 0; j < sz(x); ++j) {
			if (i == j) {
				continue;
			}
			if (x[j] == y[i]) {
				++b;
			}
		}
	}
	return {a, b};
}

void build(string s, vector<string>& strings) {
	if (sz(s) == 4) {
		strings.pb(s);
		return;
	}
	for (char c = '0'; c <= '9'; ++c) {
		bool ok = true;
		for (int i = 0; i < sz(s); ++i) {
			if (s[i] == c) {
				ok = false;
				break;
			}
		}
		if (ok) {
			build(s + c, strings);
		}
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    vector<string> strings;
    string s = "";
    build(s, strings);

    int q;
    cin >> q;

    while (q--) {
    	cin >> s;
    	pii p;
    	cin >> p.first >> p.second;
    	vector<string> nx;
    	for (string& t : strings) {
    		if (f(t, s) == p) {
    			nx.pb(t);
    		}
    	}
    	strings.swap(nx);
    }

    if (sz(strings) > 1) {
    	cout << "Need more data\n";
    } else if (sz(strings) == 0) {
    	cout << "Incorrect data\n";
    } else {
    	cout << strings[0] << "\n";
    }

}