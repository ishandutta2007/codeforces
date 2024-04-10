#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi a;
int n;
vector<ll> suff, pref;

ll getright(int pos, int k) {
    int id1 = n - 1 - (upper_bound(a.rbegin(), a.rend(), k) - a.rbegin() - 1);
    id1 = max(id1, pos + 1);
    return suff[id1] + (ll)k * (id1 - pos - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pref.assign(n + 1, 0);
    suff.assign(n + 1, 0);
    sort(a.rbegin(), a.rend());
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    for(int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }
    vector<ll> mxleft(n);
    for(int i = 0; i < n; i++) {
        ll l = pref[i + 1];
        int k = i + 2;
        ll r = (ll)k * (k - 1) + getright(i, k);
        /*if(i == 0) {
            cout << l << ' ' << r << endl;
        }*/
        mxleft[i] = r - l;
    }
    vector<ll> mnright(n);
    for(int i = 0; i < n; i++) {
        ll l = pref[i + 1];
        int k = i + 1;
        ll r = (ll)k * (k - 1) + getright(i, k);
        if(l - r > k) {
            mnright[i] = inf;
            continue;
        }
        mnright[i] = l - r;
    }
    vector<ll> a1(n), a2(n);
    a1[n - 1] = mxleft[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        a1[i] = min(mxleft[i], a1[i + 1]);
    }
    a2[0] = mnright[0];
    for(int i = 1; i < n; i++) {
        a2[i] = max(mnright[i], a2[i - 1]);
    }
    bool haveans = false;
    for(int i = 0; i <= n; i++) {
        if((i + pref[n]) % 2 == 1) continue;
        int id1 = n - 1 - (upper_bound(a.rbegin(), a.rend(), i) - a.rbegin());
        bool ok = true;
        if(id1 != -1) {
            if(a2[id1] > i) ok = false;
        }
        if(id1 != n - 1) {
            if(a1[id1 + 1] < i) ok = false;
        }
        if(id1 != n - 1) {
            int k = id1 + 2;
            ll l = pref[id1 + 1] + i;
            ll r = (ll)k * (k - 1) + getright(id1, k);
            if(l > r) ok = false;
        }
        if(ok) {
            cout << i << ' ';
            haveans = true;
        }
    }
    if(!haveans) {
        cout << -1;
    }
}