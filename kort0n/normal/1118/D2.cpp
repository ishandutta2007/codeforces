#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll n, m;
vector<ll> a;
ll sum[200050];

int main() {
    //cout.precision(10);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        ll in;
        cin >> in;
        a.push_back(in);
    }
    sort(a.begin(), a.end(), greater<ll>());
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    if(sum[n] < m) {
        cout << -1 << endl;
        return 0;
    }
    ll ok = n;
    ll ng = 0;
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        ll cleared = false;
        ll damage = 0;
        for(ll i = 1; i <= n; i++) {
            damage += (i - 1) / mid;
            if(sum[i] - damage >= m) cleared = true;
        }
        if(cleared) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}