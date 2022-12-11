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

const int alpha = 26;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	string s;
    	cin >> s;
    	vector<int> cnt(alpha, 0);
    	for (int i = 0; i < sz(s); ++i) {
    		++cnt[s[i] - 'a'];
    	}
    	int diff = 0;
    	for (int i = 0; i < alpha; ++i) {
    		if (cnt[i]) {
    			++diff;
    		}
    	}
    	if (diff == 1) {
    		cout << s << "\n";
    		continue;
    	}

    	int single = -1;
    	for (int i = 0; i < alpha; ++i) {
    		if (cnt[i] == 1) {
    			single = i;
    			break;
    		}
    	}
    	if (single != -1) {
    		cout << char(single + 'a');
    		--cnt[single];
    		for (int i = 0; i < alpha; ++i) {
    			while (cnt[i]--) {
    				cout << char(i + 'a');
    			}
    		}
    		cout << "\n";
    		continue;
    	}
   		
   		int a;
   		for (int i = 0; i < alpha; ++i) {
   			if (cnt[i]) {
   				a = i;
   				break;
   			}
   		}
   		if (cnt[a] <= 2) {
   			for (int i = 0; i < alpha; ++i) {
   				while (cnt[i]--) {
   					cout << char(i + 'a');
   				}
   			}
   			cout << "\n";
   			continue;
   		}

   		vector<char> bank;
   		for (int i = alpha - 1; i >= 0; --i) {
   			if (i == a) {
   				continue;
   			}
   			for (int j = 0; j < cnt[i]; ++j) {
   				bank.pb(char(i + 'a'));
   			}
   		}

   		if (cnt[a] - 2 <= sz(bank)) {
   			cout << char(a + 'a') << char(a + 'a');
   			cnt[a] -= 2;
   			while (cnt[a]--) {
   				cout << bank.back();
   				bank.pop_back();
   				cout << char(a + 'a');
   			}
   			while (!bank.empty()) {
   				cout << bank.back();
   				bank.pop_back();
   			}
   			cout << "\n";
   			continue;
   		}

   		if (diff >= 3) {
   			int b = -1, c = -1;
   			for (int i = 0; i < alpha; ++i) {
   				if (i == a) {
   					continue;
   				}
   				if (!cnt[i]) {
   					continue;
   				}
   				if (b == -1) {
   					b = i;
   				} else {
   					c = i;
   					break;
   				}
   			}
   			cout << char(a + 'a') << char(b + 'a');
   			--cnt[a], --cnt[b];
   			while (cnt[a]--) {
   				cout << char(a + 'a');
   			}
   			cout << char(c + 'a');
   			--cnt[c];
   			for (int i = 0; i < alpha; ++i) {
   				if (cnt[i] <= 0) continue;
   				while (cnt[i]--) {
   					cout << char(i + 'a');
   				}
   			}
   			cout << "\n";
   		} else {
   			int b;
   			for (int i = 0; i < alpha; ++i) {
   				if (cnt[i] && i != a) {
   					b = i;
   				}
   			}
   			cout << char(a + 'a');
   			--cnt[a];
   			while (cnt[b]--) {
   				cout << char(b + 'a');
   			}
   			while (cnt[a]--) {
   				cout << char(a + 'a');
   			}
   			cout << "\n";
   		}
    }

}