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

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    int opt = -1;
    for (int i = 0; i < n; ++i) {
    	if (sz(a[i]) < sz(s)) {
    		continue;
    	}
    	if (a[i].substr(0, sz(s)) != s) {
    		continue;
    	}
    	if (opt == -1 || a[i] < a[opt]) {
    		opt = i;
    	}
    }

    if (opt != -1) {
    	cout << a[opt];
    } else {
    	cout << s;
    }
    cout << "\n";

}