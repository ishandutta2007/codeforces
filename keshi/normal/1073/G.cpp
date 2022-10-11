//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, q, rnk[maxn], per[maxn], r2[maxn], p2[maxn], lcp[maxn], ps[maxn], cnt, sa[maxn], sb[maxn], ans[maxn];
string s;
vector<ll> a[maxn], b[maxn], g1[maxn], g2[maxn], vec;

int main(){
    fast_io;

    cin >> n >> q;
    n++;
    cin >> s;
    s += ' ';
    cnt = 300;
    for(ll i = 0; i < n; i++){
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
        if(s[per[i]] != s[per[i - 1]]) cnt++;
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
    for(ll i = 0; i < q; i++){
        cin >> sa[i] >> sb[i];
        a[i].resize(sa[i]);
        b[i].resize(sb[i]);
        for(ll j = 0; j < sa[i]; j++){
            cin >> a[i][j];
            a[i][j] = rnk[a[i][j] - 1];
            g1[a[i][j]].pb(i);
        }
        for(ll j = 0; j < sb[i]; j++){
            cin >> b[i][j];
            b[i][j] = rnk[b[i][j] - 1];
            g2[b[i][j]].pb(i);
        }
        sort(all(a[i]));
        sort(all(b[i]));
        for(ll j = 0; j < sa[i]; j++){
            if(binary_search(all(b[i]), a[i][j])) ans[i] += n - per[a[i][j]] - 1;
        }
    }
    for(ll i = 0, k = 0; i < n; i++){
        if(rnk[i] == n - 1){
            k = 0;
            continue;
        }
        ll j = per[rnk[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rnk[i]] = k;
        if(k) k--;
    }
    lcp[0] = lcp[n - 1] = -1;
    vec.pb(0);
    for(ll i = 1; i < n; i++){
        while(lcp[i] < lcp[vec.back()]){
            ll x = vec.back();
            vec.pop_back();
            if(x - vec.back() < i - x){
                for(ll j = vec.back() + 1; j <= x; j++){
                    for(ll k : g1[j]){
                        ans[k] += lcp[x] * (upper_bound(all(b[k]), i) - upper_bound(all(b[k]), x));
                    }
                    for(ll k : g2[j]){
                        ans[k] += lcp[x] * (upper_bound(all(a[k]), i) - upper_bound(all(a[k]), x));
                    }
                }
            }
            else{
                for(ll j = x + 1; j <= i; j++){
                    for(ll k : g1[j]){
                        ans[k] += lcp[x] * (upper_bound(all(b[k]), x) - upper_bound(all(b[k]), vec.back()));
                    }
                    for(ll k : g2[j]){
                        ans[k] += lcp[x] * (upper_bound(all(a[k]), x) - upper_bound(all(a[k]), vec.back()));
                    }
                }
            }
        }
        vec.pb(i);
    }
    for(ll i = 0; i < q; i++){
        cout << ans[i] << '\n';
    }


    return 0;
}