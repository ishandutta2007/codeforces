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

char upe(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c;
	}
	return char(c - 'a' + 'A');
}

char low(char c) {
	if (c >= 'a' && c <= 'z') {
		return c;
	}
	return char(c - 'A' + 'a');
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int lower = 0, upper = 0;
    for (int i = 0; i < sz(s); ++i) {
    	if (s[i] >= 'A' && s[i] <= 'Z') {
    		++upper;
    	} else {
    		++lower;
    	}
    }

    if (upper > lower) {
    	for (int i = 0; i < sz(s); ++i) {
    		cout << upe(s[i]);
    	}
    } else {
    	for (int i = 0; i < sz(s); ++i) {
    		cout << low(s[i]);
    	}
    }
    cout << "\n";

}