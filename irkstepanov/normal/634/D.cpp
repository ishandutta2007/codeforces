#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 1e9;

int N;
vector<pii> t;

pii get(int l, int r)
{
    pii ans = {inf, inf};
    for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            if (ans.first > t[l].first || (ans.first == t[l].first && ans.second > t[l].second)) {
                ans = t[l];
            }
        }
        if (!(r & 1)) {
            if (ans.first > t[r].first || (ans.first == t[r].first && ans.second > t[r].second)) {
                ans = t[r];
            }
        }
    }
    return ans;
}

int main()
{

    //ios::sync_with_stdio(false);

    int d, n, m;
    scanf("%d%d%d", &d, &n, &m);

    N = m + 2;
    t.resize(2 * N);
    vector<pii> v(N);
    v[0] = {0, 0};
    v[m + 1] = {d, 0};
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &v[i].first, &v[i].second);
    }

    sort(all(v));
    for (int i = 0; i <= m; ++i) {
        if (v[i + 1].first - v[i].first > n) {
            printf("-1\n");
            return 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        t[i + N] = mp(v[i].second, i);
    }
    for (int i = N - 1; i; --i) {
        if (t[i * 2].first <= t[i * 2 + 1].first) {
            t[i] = t[i * 2];
        } else {
            t[i] = t[i * 2 + 1];
        }
    }

    vector<int> firstLess(N);
    firstLess[0] = -1;
    firstLess[N - 1] = -1;
    for (int i = N - 2; i; --i) {
        if (v[i].second > v[i + 1].second) {
            firstLess[i] = i + 1;
            continue;
        }
        int curr = i + 1;
        while (v[curr].second >= v[i].second) {
            curr = firstLess[curr];
        }
        firstLess[i] = curr;
    }

    int curr = 0;
    int petrol = n;
    ll ans = 0;

    while (curr != N - 1) {
        int pos = v[curr].first;
        int l = lower_bound(all(v), mp(min(pos + n, d), -1)) - v.begin();
        if (v[l].first > min(pos + n, d)) {
            --l;
        }
        pii p = get(curr + 1, l);
        if (firstLess[curr] != -1 && firstLess[curr] < p.second) {
            p.second = firstLess[curr];
        }
        if (v[p.second].second > v[curr].second) {
            int delta = n - petrol;
            ans += (ll)(delta) * (v[curr].second);
            petrol = n;
            petrol -= (v[p.second].first - v[curr].first);
        }
        else if (petrol < v[p.second].first - v[curr].first) {
            int delta = v[p.second].first - v[curr].first - petrol;
            ans += (ll)(delta) * (ll)(v[curr].second);
            petrol = 0;
        } else {
            petrol -= (v[p.second].first - v[curr].first);
        }
        curr = p.second;
    }

    cout << ans << "\n";

}