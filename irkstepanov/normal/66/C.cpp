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

    map<string, set<string> > folders, files;

    string s;
    while (cin >> s) {
    	int pos = -1;
    	for (int i = 3; ; ++i) {
    		if (s[i] == '\\') {
    			pos = i;
    			break;
    		}
    	}
    	string folder = s.substr(0, pos);
    	for (int i = pos + 1; i < sz(s); ++i) {
    		if (s[i] == '\\') {
    			folders[folder].insert(s.substr(pos, i - pos + 1));
    		}
    	}
    	files[folder].insert(s.substr(pos, sz(s) - pos));
    }

    int ans = 0;

    for (auto it : folders) {
    	ans = max(ans, sz(it.second));
    }
    cout << ans << " ";
    ans = 0;

    for (auto it : files) {
    	ans = max(ans, sz(it.second));
    }
    cout << ans << "\n";

}