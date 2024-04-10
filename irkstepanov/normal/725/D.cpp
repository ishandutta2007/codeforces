#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> t(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> w[i];
    }

    int ans = 1;
    multiset<ll> better;
    vector<pll> leq;
    for (int i = 1; i < n; ++i) {
        if (t[i] > t[0]) {
            ++ans;
            better.insert(w[i] - t[i] + 1);
        } else {
            leq.pb({t[i], w[i]});
        }
    }

    sort(all(leq));
    int curr = ans;

    while (!better.empty()) {
        multiset<ll>::iterator it = better.begin();
        if (*it > t[0]) {
            break;
        }
        ll spend = *it;
        better.erase(it);
        t[0] -= spend;
        while (!leq.empty() && leq.back().first > t[0]) {
            better.insert(leq.back().second - leq.back().first + 1);
            leq.pop_back();
        }
        curr = sz(better) + 1;
        ans = min(ans, curr);
    }

    cout << ans << "\n";

}