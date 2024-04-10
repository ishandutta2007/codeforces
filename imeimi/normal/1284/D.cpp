#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

struct lecture {
    int sa, ea, sb, eb;
    void scan() {
        cin >> sa >> ea >> sb >> eb;
    }
    void swap() {
        ::swap(sa, sb);
        ::swap(ea, eb);
    }
} ls[100001];

int n;

bool check() {
    vector<pii> ev;
    for (int i = 1; i <= n; ++i) {
        ev.emplace_back(ls[i].sa << 1, i);
        ev.emplace_back(ls[i].ea << 1 | 1, -i);
    }
    sort(ev.begin(), ev.end());
    multiset<int> ss, ee;
    for (pii i : ev) {
        if (i.se < 0) {
            int x = -i.se;
            ss.erase(ss.find(ls[x].sb));
            ee.erase(ee.find(ls[x].eb));
        }
        else {
            int x = i.se;
            if (!ss.empty() && ls[x].eb < *ss.rbegin()) return 0;
            if (!ee.empty() && ls[x].sb > *ee.begin()) return 0;
            ss.insert(ls[x].sb);
            ee.insert(ls[x].eb);
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ls[i].scan();
    }
    if (!check()) {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        ls[i].swap();
    }
    if (!check()) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}