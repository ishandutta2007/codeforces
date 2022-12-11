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

    int n;
    cin >> n;
    ++n;
    string s;
    cin >> s;
    s += "?";

    //vector<char> a = {'G', 'H', 'R', 'S'};
    vector<string> names = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};
    vector<vector<int> > curr;
    curr.pb({0, 0, 0, 0});
    vector<string> ans;

    for (int i = 0; i < n; ++i) {
    	vector<vector<int> > nx;
    	ans.clear();
    	for (vector<int>& x : curr) {
    		if (s[i] == 'G') {
    			vector<int> y = x;
    			++y[0];
    			nx.pb(y);
    		} else if (s[i] == 'H') {
    			vector<int> y = x;
    			++y[1];
    			nx.pb(y);
    		} else if (s[i] == 'R') {
    			vector<int> y = x;
    			++y[2];
    			nx.pb(y);
    		} else if (s[i] == 'S') {
    			vector<int> y = x;
    			++y[3];
    			nx.pb(y);
    		} else {
    			vector<int> y = x;
    			for (int j = 0; j < 4; ++j) {
    				if (y[j] <= y[0] && y[j] <= y[1] && y[j] <= y[2] && y[j] <= y[3]) {
    					++y[j];
    					nx.pb(y);
    					ans.pb(names[j]);
    					--y[j];
    				}
    			}
    		}
    	}
    	sort(all(nx));
    	nx.resize(unique(all(nx)) - nx.begin());
    	curr = nx;
    }

    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    for (int i = 0; i < sz(ans); ++i) {
    	cout << ans[i] << "\n";
    }

}