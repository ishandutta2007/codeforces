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

const int ops = 100;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ld> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    sort(all(a));

    ld lf = 0, rg = 1e9;
    for (int op = 0; op < ops; ++op) {
    	ld md = (lf + rg) / 2;
    	int pos = 0;
    	int cnt = 0;
    	while (pos < n) {
    		ld x = a[pos] + md * 2;
    		while (pos < n && a[pos] <= x) {
    			++pos;
    		}
    		++cnt;
    	}
    	if (cnt <= 3) {
    		rg = md;
    	} else {
    		lf = md;
    	}
    }

    cout << fixed;
    cout.precision(6);

    int pos = 0;
    ld md = rg + 1e-7;
    cout << lf << "\n";
    int cnt = 0;
    while (pos < n) {
    	cout << a[pos] + md << " ";
		ld x = a[pos] + md * 2;
		while (pos < n && a[pos] <= x) {
			++pos;
		}
		++cnt;
	}
	while (cnt < 3) {
		cout << "0.000000 ";
		++cnt;
	}
	cout << "\n";

}