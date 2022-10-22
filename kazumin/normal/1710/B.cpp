#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct rain {
    int x, p, i;
};

bool cmp(rain p, rain q) {
    return p.x < q.x;
}

const int MN = 200005;

int n, m, amt[MN], ok[MN];
rain a[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].p, a[i].i = i, amt[i] = 0;
        sort(a + 1, a + n + 1, cmp);
        int lvl = 0, slp = 0, pre = 0;
        priority_queue<pii, vector<pii>, greater<>> q;
        for (int i = 1; i <= n; i++) q.push({a[i].x, i});
        while (q.size()) {
            pii cur = q.top(); q.pop();
            lvl += slp * (cur.f - pre);
            //printf("%lld %lld %lld %lld\n", lvl, slp, cur.f, pre);
            if (cur.s) {
                lvl += a[cur.s].p;
                slp--;
                amt[cur.s] += lvl;
                q.push({cur.f + a[cur.s].p, 0});
            } else slp++;
            pre = cur.f;
        }
        lvl = 0, slp = 0, pre = 0;
        priority_queue<pii> qq;
        for (int i = 1; i <= n; i++) qq.push({a[i].x, i});
        while (qq.size()) {
            pii cur = qq.top(); qq.pop();
            lvl += slp * (pre - cur.f);
            if (cur.s) {
                slp--;
                amt[cur.s] += lvl;
                lvl += a[cur.s].p;
                qq.push({cur.f - a[cur.s].p, 0});
            } else slp++;
            pre = cur.f;
        }
        for (int i = 1; i <= n; i++) ok[i] = 1;
        int lft = 1e12, pos = 0, hgt = -1e12;
        for (int i = 1; i <= n; i++) {
            //printf("%lld\n", amt[i]);
            if (amt[i] > m) lft = min(lft, a[i].x);
            if (lft <= a[i].x - a[i].p) ok[a[i].i] = 0;
            if (amt[i] > m && hgt - pos < amt[i] - a[i].x) hgt = amt[i], pos = a[i].x;
            int dif = min(a[i].p, a[i].x - pos);
            if (hgt > m && hgt - (a[i].p - dif) > m) {
                //printf("%lld %lld %lld\n", a[i].i, hgt, dif);
                ok[a[i].i] = 0;
            }
        }
        int rit = -1e12;
        pos = 0, hgt = -1e12;
        for (int i = n; i > 0; i--) {
            if (amt[i] > m) rit = max(rit, a[i].x);
            if (rit >= a[i].x + a[i].p) ok[a[i].i] = 0;
            if (amt[i] > m && hgt + pos < amt[i] + a[i].x) hgt = amt[i], pos = a[i].x;
            int dif = min(a[i].p, pos - a[i].x);
            if (hgt > m && hgt - (a[i].p - dif) > m) ok[a[i].i] = 0;
        }
        for (int i = 1; i <= n; i++) printf("%d", ok[i]);
        printf("\n");
    }

    return 0;
}