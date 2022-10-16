#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n;
ll q[200500];
ll a[200050];
bool already[200050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i < n; i++) cin >> q[i];
    ll sum = 0;
    for(ll i = 1; i < n; i++) {
        sum += (n - i) * q[i];
    }
    a[1] = ((n*(n+1)/2) - sum) / n;
    for(int i = 2; i <= n; i++) a[i] = a[i-1] + q[i-1];
    for(int i = 1; i <= n; i++) {
        if(a[i] < 1 || a[i] > n) {
            cout << -1 << endl;
            return 0;
        }
        if(already[a[i]]) {
            cout << -1 << endl;
            return 0;
        }
        already[a[i]] = true;
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}