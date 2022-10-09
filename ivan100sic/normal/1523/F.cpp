// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll vr[1 << 14][105];  // (kule, skor) -> min vreme da se to postigne
int sk[1 << 14][105];

int n, m;
int x[14], y[14];
int u[105], v[105], t[105];

void rq() {
    vector<array<int, 3>> a(m);
    for (int i=0; i<m; i++) {
        cin >> a[i][1] >> a[i][2] >> a[i][0];
    }
    sort(begin(a), end(a));
    for (int i=0; i<m; i++) {
        u[i] = a[i][1];
        v[i] = a[i][2];
        t[i] = a[i][0];
    }
}

struct event {
    ll t;
    int tip, mask, arg;

    bool operator< (const event& o) const {
        return tie(t, tip, mask, arg) < tie(o.t, o.tip, o.mask, o.arg);
    }
};

ll dist(int mask, int xt, int yt) {
    ll dt = 1e18;
    for (int i=0; i<n; i++) {
        if (mask & (1 << i)) {
            dt = min(dt, 0ll + abs(xt - x[i]) + abs(yt - y[i]));
        }
    }
    return dt;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }

    rq();

    memset(vr, 63, sizeof vr);
    set<event> pq;

    for (int i=0; i<n; i++) {
        vr[1 << i][0] = 0;
        pq.insert({0, 1, 1 << i, 0});
    }

    for (int j=0; j<m; j++) {
        sk[0][j] = 1;
        pq.insert({t[j], 0, 0, j});
    }

    while (pq.size()) {
        auto ev = *pq.begin();
        pq.erase(pq.begin());

        if (ev.tip == 1) {
            // nalazimo se u nekom od tornjeva, imamo neki skor
            for (int i=0; i<n; i++) {
                // idi u toranj -> i

                const int mask2 = ev.mask | (1 << i);
                if (ev.mask != mask2) {
                    ll vr2 = ev.t + dist(ev.mask, x[i], y[i]);
                    if (vr2 < vr[mask2][ev.arg]) {
                        pq.erase({vr[mask2][ev.arg], 1, mask2, ev.arg});
                        vr[mask2][ev.arg] = vr2;
                        pq.insert({vr[mask2][ev.arg], 1, mask2, ev.arg});
                    }
                }
            }
        } else {
            // sazreo je quest
            int qid = ev.arg;

            for (int mask=0; mask<(1<<n); mask++) {
                int hs = mask == 0 ? 1 : -1;
                // idemo od neke kulice
                ll d = dist(mask, u[qid], v[qid]);
                for (int s=qid; s>=0; s--) {
                    if (d + vr[mask][s] <= t[qid]) {
                        // quest success
                        hs = max(hs, s+1);
                        break;
                    }
                }

                // idemo od nekog questa
                for (int j=0; j<qid; j++) {
                    ll d = abs(u[qid] - u[j]) + abs(v[qid] - v[j]);
                    if (d + t[j] <= t[qid] && sk[mask][j] != -1) {
                        // moze
                        hs = max(hs, sk[mask][j] + 1);
                    }
                }

                // okej hs je izracunat
                sk[mask][qid] = hs;

                // nema beganje nigde ako ne valja
                if (hs != -1) {
                    // odmah idi u neki od svojih tornjeva
                    if (mask) {
                        const ll vr2 = t[qid];
                        if (vr2 < vr[mask][hs]) {
                            pq.erase({vr[mask][hs], 1, mask, hs});
                            vr[mask][hs] = vr2;
                            pq.insert({vr[mask][hs], 1, mask, hs});
                        }
                    }

                    // mozda dodatno hoces da odes do novog tornja odavde?
                    for (int i=0; i<n; i++) {
                        // idi u toranj -> i
                        const int mask2 = mask | (1 << i);
                        if (mask != mask2) {
                            ll vr2 = t[qid] + abs(u[qid] - x[i]) + abs(v[qid] - y[i]);
                            if (vr2 < vr[mask2][hs]) {
                                pq.erase({vr[mask2][hs], 1, mask2, hs});
                                vr[mask2][hs] = vr2;
                                pq.insert({vr[mask2][hs], 1, mask2, hs});
                            }
                        }
                    }
                }
            }
        }
    }

    int sol = 0;

    for (int mask=0; mask<(1<<n); mask++) {
        for (int i=0; i<m; i++) {
            // cerr << mask << ' ' << i << " sk -> " << sk[mask][i] << '\n';
            sol = max(sol, sk[mask][i]);
        }

        for (int i=0; i<=m; i++) {
            // cerr << mask << ' ' << i << " vr -> " << vr[mask][i] << '\n';
        }
    }

    cout << sol << '\n';
}