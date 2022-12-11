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

    int tt;
    cin >> tt;

    while (tt--) {
    	int n;
    	cin >> n;
    	vector<int> a(n + 1);
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	if (a[1] == 1) {
    		cout << n + 1 << " ";
    		for (int i = 1; i <= n; ++i) {
    			cout << i << " ";
    		}
    		cout << "\n";
    		continue;
    	}
    	if (a[n] == 0) {
    		for (int i = 1; i <= n + 1; ++i) {
    			cout << i << " ";
    		}
    		cout << "\n";
    		continue;
    	}
    	int pos = -1;
    	for (int i = 1; ; ++i) {
    		if (a[i] == 0 && a[i + 1] == 1) {
    			pos = i;
    			break;
    		}
    	}
    	for (int i = 1; i <= pos; ++i) {
    		cout << i << " ";
    	}
    	cout << n + 1 << " ";
    	for (int i = pos + 1; i <= n; ++i) {
    		cout << i << " ";
    	}
    	cout << "\n";
    }

}