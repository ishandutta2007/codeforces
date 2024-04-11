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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll M, N;
    cin >> N >> M;
    vector<ll> L(M);
    ll Lsum = 0;
    for(int i = 0; i < M; i++) {
        cin >> L[i];
        Lsum += L[i];
    }
    if(Lsum < N) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> ans(M);
    for(int i = 0; i < M; i++) {
        ll tmp = i + 1;
        if(tmp + L[i] - 1 > N) {
            cout << -1 << endl;
            return 0;
        }
        chmax(tmp, N + 1 - Lsum);
        ans[i] = tmp;
        Lsum -= L[i];
    }
    for(int i = 0; i < M; i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}