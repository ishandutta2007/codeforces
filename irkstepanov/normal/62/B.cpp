#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int sigma = 26;
const int inf = 1e9;

int main()
{
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
                                               
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    int len;
    cin >> q >> len;
    string s;
    cin >> s;

    vector<vector<int> > pos(sigma);
    for (int i = 0; i < sz(s); ++i) {
    	pos[s[i] - 'a'].pb(i);
    }
    while (q--) {
    	string t;
    	cin >> t;
    	ll ans = 0;
    	for (int i = 0; i < sz(t); ++i) {
    		int c = t[i] - 'a';
    		if (pos[c].empty()) {
    			ans += sz(t);
    		} else {
    			int p = lower_bound(all(pos[c]), i) - pos[c].begin();
    			int val = inf;
    			if (p < sz(pos[c])) {
    				val = min(val, abs(i - pos[c][p]));
    			}
    			--p;
    			if (p >= 0) {
    				val = min(val, abs(i - pos[c][p]));
    			}
    			ans += val;
    		}
    	}
    	cout << ans << "\n";
    }

}