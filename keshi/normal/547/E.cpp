#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define all(vec) (vec).begin(), (vec).end()
#define Sz(x) ll((x).size())

ll m, q, n, rnk[maxn], per[maxn], r2[maxn], p2[maxn], ps[maxn], cnt, lcp[maxn], fl[maxn], fr[maxn], fp[maxn], ans[maxn], fen[maxn];
string t[maxn], s;
vector<pll> g[maxn];

void upd(ll x, ll y){
    for(x += 5; x < maxn; x += x & -x){
        fen[x] += y;
    }
    return;
}
ll get(ll x){
    ll y = 0;
    for(x += 5; x > 0; x -= x & -x){
        y += fen[x];
    }
    return y;
}

int main(){
    fast_io;

    cin >> m >> q;
    for(ll i = 1; i <= m; i++){
        cin >> t[i];
        fill(fp + Sz(s), fp + Sz(s) + Sz(t[i]), i);
        s += t[i] + '#';
    }
    n = s.size();

    cnt = 300;
    for(ll i = 0; i < n; i++){
        g[i].reserve(8);
        ps[(ll)s[i]]++;
    }
    for(ll i = 1; i < cnt; i++){
        ps[i] += ps[i - 1];
    }
    for(ll i = n; i--;){
        per[--ps[(ll)s[i]]] = i;
    }
    rnk[per[0]] = 0;
    cnt = 1;
    for(ll i = 1; i < n; i++){
        if(s[per[i - 1]] != s[per[i]]) cnt++;
        rnk[per[i]] = cnt - 1;
    }
    for(ll h = 0; (1 << h) < n; h++){
        fill(ps, ps + cnt, 0);
        for(ll i = 0; i < n; i++){
            p2[i] = per[i] - (1 << h);
            if(p2[i] < 0) p2[i] += n;
        }
        for(ll i = 0; i < n; i++){
            ps[rnk[p2[i]]]++;
        }
        for(ll i = 1; i < cnt; i++){
            ps[i] += ps[i - 1];
        }
        for(ll i = n; i--;){
            per[--ps[rnk[p2[i]]]] = p2[i];
        }
        for(ll i = 0; i < n; i++){
            p2[i] = per[i] + (1 << h);
            if(p2[i] >= n) p2[i] -= n;
        }
        r2[per[0]] = 0;
        cnt = 1;
        for(ll i = 1; i < n; i++){
            if(rnk[per[i]] != rnk[per[i - 1]] || rnk[p2[i]] != rnk[p2[i - 1]]) cnt++;
            r2[per[i]] = cnt - 1;
        }
        for(ll i = 0; i < n; i++){
            rnk[i] = r2[i];
        }
    }
    /*for(ll i = 0; i < n; i++){
        cout << i << " ";
        for(ll j = per[i]; j < n; j++){
            cout << s[j];
        }
        cout << '\n';
    }*/
    for(ll i = 1; i <= m; i++){
        ll l, r, mid;
        bool f;
        l = -1, r = n;
        while(r - l > 1){
            mid = (l + r) >> 1;
            f = 0;
            for(ll j = 0; j < min(n - per[mid], Sz(t[i])); j++){
                if(s[per[mid] + j] > t[i][j]){
                    f = 1;
                    break;
                }
                if(s[per[mid] + j] < t[i][j]){
                    break;
                }
            }
            if(f) r = mid;
            else l = mid;
        }
        fr[i] = l;
        l = -1, r = n;
        while(r - l > 1){
            mid = (l + r) >> 1;
            f = 1;
            for(ll j = 0; j < min(n - per[mid], Sz(t[i])); j++){
                if(s[per[mid] + j] > t[i][j]){
                    break;
                }
                if(s[per[mid] + j] < t[i][j]){
                    f = 0;
                    break;
                }
            }
            if(f) r = mid;
            else l = mid;
        }
        fl[i] = l;
        //cout << "? " << fl[i] << " " << fr[i] << '\n';
    }
    for(ll i = 1; i <= q; i++){
        ll l, r, k;
        cin >> l >> r >> k;
        g[fr[k]].pb(Mp(r, i));
        g[fr[k]].pb(Mp(l - 1, -i));
        g[fl[k]].pb(Mp(r, -i));
        g[fl[k]].pb(Mp(l - 1, i));
    }
    for(ll i = 0; i < n; i++){
        upd(fp[per[i]], 1);
        for(pll j : g[i]){
            if(j.S > 0) ans[j.S] += get(j.F);
            else ans[-j.S] -= get(j.F);
        }
    }
    for(ll i = 1; i <= q; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}