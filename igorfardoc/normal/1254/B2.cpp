#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll ans = 0;
ll k;

ll calc(vi& a, ll k) {
    //cout << a.size() << endl;
    ll res = 0;
    ll sumhere = 0;
    int id1 = -1;
    ll need = (k - 1) / 2 + 1;
    for(int i = 0; i < a.size(); i++) {
        sumhere += a[i];
        if(sumhere >= need) {
            id1 = i;
            break;
        }
    }
    for(int i = 0; i < a.size(); i++) {
        res += (ll)a[i] * abs(id1 - i);
    }
    return res;
}

ll check(vi a, ll k) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        a[i] %= k;
    }
    ll res = 0;
    ll need = k;
    vi now;
    //cout << k << endl;
    for(int i = 0; i < n; i++) {
        int can = min((ll)a[i], need);
        now.push_back(can);
        a[i] -= can;
        need -= can;
        if(need == 0) {
            res += calc(now, k);
            now.clear();
            need = k - a[i];
            now.push_back(a[i]);
        }
    }
    return res;
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
    int n;
    cin >> n;
    vi a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum <= 1) {
        cout << -1;
        return 0;
    }
    ll ans = 1e18;
    ll now = sum;
    ll i = 2;
    while(now > 1 && i * i <= now) {
        if(now % i == 0) {
            ans = min(ans, check(a, i));
        }
        while(now % i == 0) {
            now /= i;
        }
        ++i;
    }
    if(now > 1) {
        ans = min(ans, check(a, now));
    }
    cout << ans;
}