#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

struct data
{
    int l, r, h;
};

vector<int> t;
int N;

void update(int l, int r, int val)
{
    for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            t[l] = max(t[l], val);
        }
        if (!(r & 1)) {
            t[r] = max(t[r], val);
        }
    }
}

int get(int pos)
{
    int ans = 0;
    for (pos += N; pos; pos >>= 1) {
        ans = max(ans, t[pos]);
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<data> a(n);
    vector<int> sorted;

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a[i].h, &a[i].l, &a[i].r);
        sorted.pb(a[i].l);
        sorted.pb(a[i].r - 1);
        sorted.pb(a[i].r);
    }
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    N = sz(sorted);
    t.resize(2 * N);

    for (int i = 0; i < n; ++i) {
        a[i].l = lower_bound(all(sorted), a[i].l) - sorted.begin();
        a[i].r = lower_bound(all(sorted), a[i].r - 1) - sorted.begin();
        update(a[i].l, a[i].r, a[i].h);
    }

    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        h[i] = get(i);
        //cout << sorted[i] << " " << h[i] << "\n";
    }

    vector<pii> ans;
    ans.pb(mp(sorted[0], 0));
    for (int i = 0; i < N; ++i) {
        if (i == N - 1) {
            ans.pb(mp(sorted[i], h.back()));
            break;
        }
        ans.pb(mp(sorted[i], h[i]));
        ans.pb(mp(sorted[i + 1], h[i]));
    }

    vector<pii> otv;
    for (int i = 0; i < sz(ans); ++i) {
        if (i > 0 && i < sz(ans) - 1 && ans[i].second == ans[i - 1].second && ans[i].second == ans[i + 1].second) {
            continue;
        }
        otv.pb(ans[i]);
    }

    ans = otv;
    printf("%d\n", sz(ans));
    for (pii& p : ans) {
        printf("%d %d\n", p.first, p.second);
    }

}