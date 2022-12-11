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

    string t = "";
    string s;
    while (getline(cin, s)) {
    	for (int i = 0; i < sz(s); ++i) {
    		if (s[i] != ' ') {
    			t += s[i];
    		}
    	}
    }

    vector<int> curr;
    vector<int> ans;
    int pos = 0;
    while (pos < sz(t)) {
    	if (pos + 3 < sz(t) && t.substr(pos, 4) == "<td>") {
    		++curr.back();
    		pos += 4;
    		continue;
    	}
    	if (pos + 6 < sz(t) && t.substr(pos, 7) == "<table>") {
    		curr.pb(0);
    		pos += 7;
    		continue;
    	}
    	if (pos + 7 < sz(t) && t.substr(pos, 8) == "</table>") {
    		ans.pb(curr.back());
    		curr.pop_back();
    		pos += 8;
    		continue;
    	}
    	++pos;
    }

    sort(all(ans));
    for (int x : ans) {
    	cout << x << " ";
    }
    cout << "\n";

}