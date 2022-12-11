#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    
    string s;
    cin >> s;

    string ans = s.substr(0, n - 1);
    for (int i = 0; i + 1 < n; ++i) {
    	if (s[i] > s[i + 1]) {
    		string t = "";
    		for (int j = 0; j < n; ++j) {
    			if (i != j) {
    				t += s[j];
    			}
    		}
    		ans = min(ans, t);
    		break;
    	}
    }

    cout << ans << "\n";
    
}