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
    	string s;
    	cin >> s;
    	int pos = -1;
    	for (int i = n / 2; i < n; ++i) {
    		if (s[i] == '0') {
    			pos = i;
    			break;
    		}
    	}
    	if (pos != -1) {
    		int l = pos - (n / 2 + 1) + 1;
    		int r = pos;
    		cout << l + 1 << " " << r + 1 << " ";
    		--r;
    		cout << l + 1 << " " << r + 1 << "\n";
    		continue;
    	}
    	int j = n / 2 - 1;
    	if (s[j] == '0') {
    		int l = j, r = n - 1;
    		cout << l + 1 << " " << r + 1 << " ";
    		++l;
    		cout << l + 1 << " " << r + 1 << "\n";
    	} else {
    		int l = j, r = n - 2;
    		cout << l + 1 << " " << r + 1 << " ";
    		++l, ++r;
    		cout << l + 1 << " " << r + 1 << "\n";
    	}
    }

}