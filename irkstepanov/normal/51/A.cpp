#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    set<vector<int> > s;

    for (int i = 0; i < n; ++i) {
    	string t;
    	cin >> t;
    	int a = t[0] - '0', b = t[1] - '0';
    	cin >> t;
    	int c = t[0] - '0', d = t[1] - '0';
    	if (i + 1 < n) {
    		cin >> t;
    	}
    	if (s.count({a, b, c, d})) {
    		continue;
    	}
    	if (s.count({c, a, d, b})) {
    		continue;
    	}
    	if (s.count({d, c, b, a})) {
    		continue;
    	}
    	if (s.count({b, d, a, c})) {
    		continue;
    	}
    	s.insert({a, b, c, d});
    }

    cout << sz(s) << "\n";

}