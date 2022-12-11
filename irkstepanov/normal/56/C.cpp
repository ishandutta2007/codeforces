#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

int f(vector<string>& s) {
	int ans = 0;
	for (int i = 0; i < sz(s) - 1; ++i) {
		if (s[i] == s.back()) {
			++ans;
		}
	}
	return ans;
}

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    vector<string> st;
    int ans = 0;
    string curr = "";

    for (int i = 0; i < sz(s); ++i) {
    	if (s[i] == ',') {
    		continue;
    	}
    	if (s[i] == ':') {
    		st.pb(curr);
    		ans += f(st);
    		curr = "";
    		continue;
    	}
    	if (s[i] == '.') {
    		if (curr != "") {
    			st.pb(curr);
    			ans += f(st);
    			curr = "";
    		}
    		st.pop_back();
    	} else {
    		curr += s[i];
    	}
    }

    cout << ans << "\n";

}