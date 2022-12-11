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
    	int first = -1;
    	for (int i = 0; i < n; ++i) {
    		if (s[i] != '?') {
    			first = i;
    			break;
    		}
    	}
    	if (first == -1) {
    		for (int i = 0; i < n; ++i) {
    			if (i & 1) {
    				cout << 'R';
    			} else {
    				cout << 'B';
    			}
    		}
    		cout << "\n";
    		continue;
    	}
    	for (int i = first - 1, j = 1; i >= 0; --i, ++j) {
    		if (j & 1) {
    			if (s[first] == 'B') {
    				s[i] = 'R';
    			} else {
    				s[i] = 'B';
    			}
    		} else {
    			s[i] = s[first];
    		}
    	}
    	char prev = s[first];
    	for (int i = first + 1; i < n; ++i) {
    		if (prev == 'R') {
    			prev = 'B';
    		} else {
    			prev = 'R';
    		}
    		if (s[i] == '?') {
    			s[i] = prev;
    		} else {
    			prev = s[i];
    		}
    	}
    	cout << s << "\n";
    }

}