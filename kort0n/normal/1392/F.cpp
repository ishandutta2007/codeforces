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

vector<ll> ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> h(N);
    ans.resize(N);
    ll sum = 0;
    for(ll i = 0; i < N; i++) {
        cin >> h[i];
        h[i] -= i;
        sum += h[i];
    }
    ll base = (sum + N - 1) / N;
    for(int i = 0; i < N; i++) {
        ans[i] = base + i;
    }
    ll rest = N * base - sum;
    for(int i = 0; i < rest; i++) {
        ans[N-1-i]--;
    }
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}