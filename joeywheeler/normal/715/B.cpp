#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n, m;
vector<pair<int,ll> > u[1005];
ll l;
int s, t;

int X[10005], Y[10005]; ll W[10005];

ll d[1005];
bool p[1005];
int prv[1005];

void djk() {
    FO(i,0,n) {
        d[i] = 1e18;
        p[i] = false;
        prv[i] = -2;
    }
    priority_queue<pair<ll,int> > pq;
    pq.emplace(0, s);
    d[s] = 0;
    prv[s] = -1;
    while (!pq.empty()) {
        auto f = pq.top(); pq.pop();
        int i = f.second;
        if (p[i]) continue;
        p[i] = true;
        for (auto e : u[i]) {
            int j = e.first; ll nd = d[i] + e.second;
            if (nd < d[j]) {
                prv[j] = i;
                d[j] = nd;
                pq.emplace(-d[j], j);
            }
        }
    }
}

int main() {
    scanf("%d %d %lld %d %d", &n, &m, &l, &s, &t);
    int c = 0;
    FO(i,0,m) {
        int x, y; ll w; scanf("%d %d %lld", &x, &y, &w);
        X[i] = x; Y[i] = y; W[i] = w;

        if (w == 0) c++;
    }
    int s = 0, e = c, b = -1;
    while (s <= e) {
        int md = (s+e)/2;
        int r = 0;
        FO(i,0,n) u[i].clear();
        FO(i,0,m) {
            int x = X[i], y = Y[i]; ll w = W[i];

            if (w == 0) {
                r++;
                if (r <= md) w = l+5;
                else w = 1;
            }

            u[x].emplace_back(y,w);
            u[y].emplace_back(x,w);
        }
        djk();
        if (d[t] == l) {
            r = 0;
            printf("YES\n");
            FO(i,0,m) {
                int x = X[i], y = Y[i]; ll w = W[i];

                if (w == 0) {
                    r++;
                    if (r <= md) w = l+5;
                    else w = 1;
                }

                printf("%d %d %lld\n", x, y, w);
            }
            return 0;
        } else if (d[t] > l) {
            b = md;
            e = md-1;
        } else {
            s = md+1;
        }
    }
    if (b <= 0) {
        printf("NO\n");
    } else {
        int md = b-1;
        int r = 0;
        FO(i,0,n) u[i].clear();
        FO(i,0,m) {
            int x = X[i], y = Y[i]; ll w = W[i];

            if (w == 0) {
                r++;
                if (r <= md) w = l+5;
                else w = 1;
            }

            u[x].emplace_back(y,w);
            u[y].emplace_back(x,w);
        }
        djk();
        //printf("d[t]=%lld\n", d[t]);
        ll ex = l - d[t];
        r = 0;
        FO(i,0,n) u[i].clear();
        printf("YES\n");
        FO(i,0,m) {
            int x = X[i], y = Y[i]; ll w = W[i];

            if (w == 0) {
                r++;
                if (r <= md) w = l+5;
                else if (r == md+1) w = 1 + ex;
                else w = 1;
            }

            u[x].emplace_back(y,w);
            u[y].emplace_back(x,w);
            printf("%d %d %lld\n", x, y, w);
        }
        djk();
        assert(d[t] == l);
    }
}