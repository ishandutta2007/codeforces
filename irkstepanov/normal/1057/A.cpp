#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
    }

    vector<int> ans;
    int curr = n;
    while (curr != 1) {
        ans.pb(curr);
        curr = p[curr];
    }
    ans.pb(1);

    reverse(all(ans));
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    
}