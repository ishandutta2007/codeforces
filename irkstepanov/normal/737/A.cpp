#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9 + 100;

struct car
{
    int c, v;
    bool operator<(const car& other) const
    {
        if (v != other.v) {
            return v < other.v;
        }
        return c < other.c;
    }
};

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, k, s, t;
    scanf("%d%d%d%d", &n, &k, &s, &t);

    vector<car> cars(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &cars[i].c, &cars[i].v);
    }
    sort(all(cars));
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &a[i]);
    }

    vector<int> dist;
    a.pb(s);
    a.pb(0);
    sort(all(a));
    for (int i = 1; i < sz(a); ++i) {
        dist.pb(a[i] - a[i - 1]);
    }
    sort(all(dist));

    int ans = inf;
    int ptr = 0; // the first: 2 * dist[ptr] > volume
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        if (cars[i].v < dist.back()) {
            continue;
        }
        while (ptr < sz(dist) && 2 * dist[ptr] <= cars[i].v) {
            sum += dist[ptr];
            ++ptr;
        }
        ll val = ll(sum) + ll(3) * ll(s - sum) - ll(cars[i].v) * ll(sz(dist) - ptr);
        if (val <= t) {
            ans = min(ans, cars[i].c);
        }
    }

    cout << (ans == inf ? -1 : ans) << "\n";

}