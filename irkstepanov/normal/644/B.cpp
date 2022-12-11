#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

struct query
{
    int id;
    ll len;
};

int main()
{

    int n, s;
    cin >> n >> s;

    ll timer = 0;
    queue<query> q;

    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        ll t, d;
        cin >> t >> d;
        while (timer < t) {
            if (q.empty()) {
                timer = t;
                break;
            }
            ll x = t - timer;
            if (x >= q.front().len) {
                ans[q.front().id] = timer + q.front().len;
                timer += q.front().len;
                q.pop();
                continue;
            } else {
                q.front().len -= x;
                timer += x;
            }
        }
        if (sz(q) <= s) {
            q.push({i, d});
        } else {
            ans[i] = -1;
        }
    }
    while (!q.empty()) {
        ans[q.front().id] = timer + q.front().len;
        timer += q.front().len;
        q.pop();
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}