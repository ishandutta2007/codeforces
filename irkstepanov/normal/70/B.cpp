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

    int k;
    cin >> k;

    vector<string> a;
    string curr = "";
    string s;
    
    while (cin >> s) {
        if (curr != "") {
            curr += " ";
        }
        curr += s;
        if (s.back() == '.' || s.back() == '?' || s.back() == '!') {
            a.pb(curr);
            curr = "";
        }
    }

    for (int i = 0; i < sz(a); ++i) {
        if (sz(a[i]) > k) {
            cout << "Impossible\n";
            return 0;
        }
    }

    int ans = 1;
    int spent = 0;
    for (int i = 0; i < sz(a); ++i) {
        if (spent) {
            ++spent;
        }
        spent += sz(a[i]);
        if (spent <= k) {
            continue;
        }
        ++ans;
        spent = sz(a[i]);
    }
    cout << ans << "\n";
    
}