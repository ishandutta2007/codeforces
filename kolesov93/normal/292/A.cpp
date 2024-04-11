#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acos(-1.);

using namespace std;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<ll, ll> > a;
    while (n--) {
        pair<ll, ll> b;
        cin >> b.first >> b.second;

        a.push_back(b);
    }

    sort(a.begin(), a.end());

    ll curt = 0;

    deque<ll> q;

    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        while (!q.empty()) {
            ll x = q.front(); q.pop_front();
            ll can = a[i].first - curt;
            if (x <= can) {
                curt += x;
                sum -= x;
            } else {
                q.push_front(x - can);
                curt = a[i].first;
                sum -= can;
                break;
            }
        }

        if (curt < a[i].first) curt = a[i].first;
        q.push_back(a[i].second);
        sum += a[i].second;
        ans = max(sum ,ans);
    }

    while (!q.empty()) {
        ll x= q.front(); q.pop_front();
        curt += x;
    }

    cout << curt << " " << ans << endl;

    return 0;
}