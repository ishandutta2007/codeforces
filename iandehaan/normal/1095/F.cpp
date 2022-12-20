#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using nxt = pair<ll, pair<ll, ll>>;
#define pb push_back
#define mp make_pair

ll inf = ((ll) 1) << 60;

ll par[200001];
ll getPar(ll x) {
    if (par[x] == x) return x;
    return par[x] = getPar(par[x]);
}

void Union(ll x, ll y) {
    if (getPar(x) == getPar(y)) return;
    par[getPar(x)] = getPar(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    priority_queue<nxt, vector<nxt>, greater<nxt>> sq;
    priority_queue<nxt, vector<nxt>, greater<nxt>> rq;
    pair<ll, ll> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    map<ll, ll> translate;
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        translate[a[i].second] = i;
    }

    for (int i = 0; i < n; i++) par[i] = i;

    for (int i = 0; i < m; i++) {
        ll w, x, y;
        cin >> x >> y >> w;
        sq.push(mp(w, mp(translate[x], translate[y])));
        //cout << w << ' ' << a[translate[x]].first << ' ' << a[translate[y]].first << endl;
    }

    for (int i = 0; i < n-1; i++) {
        rq.push(mp(a[i].first + a[i+1].first, mp(i, i+1)));
    }

    ll out = 0;
    for (int i = 0; i < n-1; i++) {
        ll sweight = inf;
        ll rweight = inf;
        pair<ll, ll> stop;
        pair<ll, ll> rtop;
        while (!sq.empty()) {
            if (getPar(sq.top().second.first) == getPar(sq.top().second.second)) {
                sq.pop();
            } else {
                sweight = sq.top().first;
                stop = sq.top().second;
                break;
            }
        }

        while (!rq.empty()) {
            ll x = rq.top().second.first;
            ll y = rq.top().second.second;
            //cout << x << ' ' << y << endl;
            ll w = rq.top().first;
            if (w > sweight) break;
            if (getPar(x) == getPar(y)) {
                rq.pop();
                if (y != n-1 && x == 0) {
                    rq.push(mp(a[x].first + a[y+1].first, mp(x, y+1)));
                }
            } else {
                rweight = w;
                rtop = rq.top().second;
                rq.pop();
                if (y != n-1 && x == 0) {
                    rq.push(mp(a[x].first + a[y+1].first, mp(x, y+1)));
                }
                break;
            }
        }

        //cout << sweight << ' ' << rweight << endl;

        if (sweight < rweight) {
            //cout << "special" << endl;
            sq.pop();
            out += sweight;
            Union(stop.first, stop.second);
        } else {
            out += rweight;
            //cout << a[rtop.first].second << ' ' << a[rtop.second].second << endl;
            //cout << sweight << endl;
            Union(rtop.first, rtop.second);
        }
    }
    cout << out << endl;
}