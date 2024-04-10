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

bool comp(const string& a, const string& b) {
	if (sz(a) != sz(b)) {
		return sz(a) < sz(b);
	}
	return a <= b;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    string x1 = "127";
    string x2 = "32767";
    string x3 = "2147483647";
    string x4 = "9223372036854775807";

    if (comp(s, x1)) {
    	cout << "byte\n";
    } else if (comp(s, x2)) {
    	cout << "short\n";
    } else if (comp(s, x3)) {
    	cout << "int\n";
    } else if (comp(s, x4)) {
    	cout << "long\n";
    } else {
    	cout << "BigInteger\n";
    }

}