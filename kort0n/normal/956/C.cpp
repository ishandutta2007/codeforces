#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N;
vector<ll> a;
vector<ll> num;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    a.resize(N);
    num.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        num[i] = a[i] + 1;
    }
    for(int i = 1; i < N; i++) {
        chmax(num[i], num[i-1]);
    }
    for(int i = N - 2; i >= 0; i--) {
        chmax(num[i], num[i+1] - 1);
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        ans += num[i] - 1 - a[i];
    }
    cout << ans << endl;
    return 0;
}