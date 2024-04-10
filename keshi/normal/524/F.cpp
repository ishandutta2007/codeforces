//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, rnk[maxn], per[maxn], r2[maxn], p2[maxn], ps[maxn], cnt, psm[maxn], spm[maxn];
bool ok[maxn];
string s;

int main(){
    fast_io;

    cin >> s;
    n = s.size();
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
    ps[0] = 0;
    for(ll i = 0; i < n; i++){
        ps[i + 1] = ps[i];
        if(s[i] == '(') ps[i + 1]++;
        else ps[i + 1]--;
    }
    psm[0] = inf;
    for(ll i = 1; i <= n; i++){
        psm[i] = min(psm[i - 1], ps[i]);
    }
    spm[n + 1] = inf;
    for(ll i = n; i > 0; i--){
        spm[i] = min(spm[i + 1], ps[i]);
    }
    ll dif = max(0, -ps[n]);
    if(psm[n] + dif >= 0) ok[0] = 1;
    for(ll i = 1; i + 1 <= n; i++){
        if(psm[i] + ps[n] - ps[i] + dif >= 0 && spm[i + 1] - ps[i] + dif >= 0) ok[i] = 1;
    }
    for(ll i = 0; i < n; i++){
        if(ok[per[i]]){
            for(ll j = 0; j < -ps[n]; j++){
                cout << '(';
            }
            for(ll j = per[i]; j < n; j++){
                cout << s[j];
            }
            for(ll j = 0; j < per[i]; j++){
                cout << s[j];
            }
            for(ll j = 0; j < ps[n]; j++){
                cout << ')';
            }
            return 0;
        }
    }


    return 0;
}