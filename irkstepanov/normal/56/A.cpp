#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> alco = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
    	string s;
    	cin >> s;
    	if (isdigit(s[0])) {
    		int a = stoi(s);
    		if (a < 18) {
    			++ans;
    		}
    	} else {
    		for (string& a : alco) {
    			if (a == s) {
    				++ans;
    			}
    		}
    	}
    }

    cout << ans << "\n";    
    
}