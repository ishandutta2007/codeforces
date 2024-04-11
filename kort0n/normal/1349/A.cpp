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
    ll N;
    cin >> N;
    ll ans = 1;
    vector<ll> a(N);
    map<ll, vector<ll>> mp;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) {
        ll copy = a[i];
        for(ll j = 2; j * j <= copy; j++) {
            if(copy % j == 0) {
                ll num = 0;
                while(copy % j == 0) {
                    copy /= j;
                    num++;
                }
                mp[j].push_back(num);
            }
        }
        if(copy != 1) {
            mp[copy].push_back(1);
        }
    }
    for(auto tmp : mp) {
        ll p = tmp.first;
        auto v = tmp.second;
        if(v.size() <= N - 2) continue;
        if(v.size() == N - 1) v.push_back(0);
        sort(v.begin(), v.end());
        while(v[1]) {
            v[1]--;
            ans *= p;
        }
    }
    cout << ans << endl;
    return 0;
}