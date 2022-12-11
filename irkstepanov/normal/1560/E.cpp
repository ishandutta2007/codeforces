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

//const int inf = 1e9;
const int sigma = 26;

string build(const string& s, vector<char>& order) {
	string ans = "";
	string curr = s;
	for (char c : order) {
		ans += curr;
		string nx = "";
		for (int i = 0; i < sz(curr); ++i) {
			if (curr[i] != c) {
				nx += curr[i];
			}
		}
		curr = nx;
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	string t;
    	cin >> t;
    	char a = t[sz(t) - 1];
    	set<char> letters;
    	vector<char> order;
    	map<char, int> mapa;
    	for (int i = sz(t) - 1; i >= 0; --i) {
    		++mapa[t[i]];
    		if (letters.count(t[i])) {
    			continue;
    		}
    		letters.insert(t[i]);
    		order.pb(t[i]);
    	}
    	reverse(all(order));
    	vector<int> goal(sigma, 0);
    	bool valid = true;
    	for (int i = 0; i < sz(order); ++i) {
    		char c = order[i];
    		if (mapa[c] % (i + 1)) {
    			valid = false;
    			break;
    		}
    		goal[c - 'a'] = mapa[c] / (i + 1);
    	}
    	if (!valid) {
    		cout << "-1\n";
    		continue;
    	}
    	vector<int> curr(sigma, 0);
    	string s = "";
    	for (int i = 0; i < sz(t) && curr != goal; ++i) {
    		char c = t[i];
    		s += c;
    		++curr[c - 'a'];
    	}
    	string result = build(s, order);
    	if (result == t) {
    		cout << s << " ";
    		for (char c : order) {
    			cout << c;
    		}
    		cout << "\n";
    	} else {
    		cout << "-1\n";
    	}
    }

}