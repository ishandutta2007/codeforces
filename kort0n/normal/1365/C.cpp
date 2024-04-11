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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        A[a] = i;
    }
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        B[a] = i;
    }
    map<int, int> mp;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int delta = B[i] - A[i] + N;
        delta %= N;
        mp[delta]++;
    }
    for(auto tmp : mp) {
        chmax(ans, tmp.second);
    }
    cout << ans << endl;
    return 0;
}