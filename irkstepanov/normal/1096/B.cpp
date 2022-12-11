#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int f = 0;
    while (s[f + 1] == s[0]) {
        ++f;
    }

    int l = n - 1;
    while (s[l - 1] == s[n - 1]) {
        --l;
    }

    //cout << f << " " << l << endl;

    ll ans = -1;
    ans += (n - 1) - (l - 1) + 1;
    ans += f + 2;

    if (s[0] == s[n - 1]) {
        ans += ll(f + 1) * ((n - 1) - (l - 1));
    }

    cout << ans % 998244353 << "\n";

}