#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	map<string, set<string> > mapa;
	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		int k;
		cin >> k;
		while (k--) {
			string t;
			cin >> t;
			mapa[s].insert(t);
		}
	}

	cout << sz(mapa) << "\n";

	for (auto it : mapa) {
		vector<string> v;
		for (string a : it.second) {
			bool ok = true;
			for (string b : it.second) {
				if (a == b) {
					continue;
				}
				if (sz(b) > sz(a) && b.substr(sz(b) - sz(a), sz(a)) == a) {
					ok = false;
					break;
				}
			}
			if (ok) {
				v.pb(a);
			}
		}
		cout << it.first << " ";
		cout << sz(v) << " ";
		for (string a : v) {
			cout << a << " ";
		}
		cout << "\n";
	}

}