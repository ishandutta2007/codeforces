#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

int main() {

    //ifstream cin("input.txt");
    //freopen("defend.out", "w", stdout);
    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    set<string> used;

    while (n--) {
        string s;
        cin >> s;
        if (used.count(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        used.insert(s);
    }

}