#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

const int rmax = 20;

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    //ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> sum(n);
    map<ll, queue<int> > m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            sum[i] = a[i];
        } else {
            sum[i] = a[i] + sum[i - 1];
        }
        m[sum[i]].push(i);
    }

    vector<int> next(n);
    ll curr = 0;
    for (int i = 0; i < n; ++i) {
        next[i] = m[curr].front();
        m[sum[i]].pop();
        m[sum[i]].push(i);
        curr += a[i];
    }

    vector<int> dist(n);
    for (int i = 0; i < n; ++i) {
        int j = (next[i] + 1) % n;
        if (i >= j) {
            j += n;
        }
        dist[i] = j - i;
    }

    vector<vector<ll> > shifts(n, vector<ll>(rmax));
    for (int i = 0; i < n; ++i) {
        shifts[i][0] = dist[i];
    }
    for (int r = 1; r < rmax; ++r) {
        for (int i = 0; i < n; ++i) {
            ll d = shifts[i][r - 1];
            int j = (d + (ll)(i)) % (ll)n;
            shifts[i][r] = d + shifts[j][r - 1];
        }
    }

    int ans = n - 1;

    for (int i = 0; i < n; ++i) {
        int pos = i;
        int cnt = 0;
        ll done = 0;
        for (int r = rmax - 1; r >= 0; --r) {
            ll d = shifts[pos][r];
            if (d + done <= (ll)n) {
                cnt += (1 << r);
                done += d;
                pos = ((ll)pos + d) % (ll)n;
            }
        }
        ans = min(ans, n - cnt);
    }

    cout << ans << "\n";

}