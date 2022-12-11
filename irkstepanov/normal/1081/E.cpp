#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

pii solve(int x, int A) {
    pii ans = {-1, -1};
    for (int d = 1; d * d <= x; ++d) {
        if (x % d) {
            continue;
        }
        int b = x / d - d;
        if (b & 1) {
            continue;
        }
        b /= 2;
        int a = b + d;
        if (a <= A) {
            ans = max(ans, {a, b});
        }
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> x(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        cin >> x[i];
    }

    vector<ll> ans;
    int A = 5e5;
    pii p = solve(x.back(), A);
    if (p.first == -1) {
        cout << "No\n";
        return 0;
    }

    ans.pb(x.back());
    A = p.second - 1;

    for (int i = n / 2 - 2; i >= 0; --i) {
        pii q = solve(x[i], A);
        if (q.first == -1) {
            cout << "No\n";
            return 0;
        }
        ans.pb(ll(A + 1) * (A + 1) - ll(q.first) * q.first);
        A = q.second - 1;
        ans.pb(x[i]);
    }

    if (A < 0) {
        cout << "No\n";
        return 0;
    }

    ans.pb(ll(A + 1) * (A + 1));

    cout << "Yes\n";
    reverse(all(ans));
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    
}