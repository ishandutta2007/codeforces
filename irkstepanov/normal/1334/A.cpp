#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tt;
    cin >> tt;

    while (tt--) {
    	int n;
    	cin >> n;
    	vector<int> a(n), b(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i] >> b[i];
    	}
    	bool ok = true;
    	int x = 0, y = 0;
    	for (int i = 0; i < n; ++i) {
    		int dx = a[i] - x, dy = b[i] - y;
    		x = a[i], y = b[i];
    		if (dy > dx || dx < 0 || dy < 0) {
    			ok = false;
    		}
    	}
    	cout << (ok ? "YES" : "NO") << "\n";
    }

}