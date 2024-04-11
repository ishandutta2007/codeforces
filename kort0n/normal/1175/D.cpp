#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll ans = 0;
ll v[300050];
vector<ll> sum;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        ans += v[i];
    }
    sum.push_back(v[n]);
    for(int i = n - 1; i >= 2; i--) {
        sum.push_back(sum.back() + v[i]);
    }
    sort(sum.begin(), sum.end(), greater<ll>());
    for(int i = 0; i < k - 1; i++) ans += sum[i];
    cout << ans << endl;
    return 0;
}