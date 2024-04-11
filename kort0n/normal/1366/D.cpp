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
ll Div[10010000];
l_l ans[500100];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(ll i = 1; i <= 1e7; i++) {
        Div[i] = -1;
    }
    for(ll i = 2; i <= 1e7; i++) {
        if(Div[i] != -1) {
            continue;
        }
        Div[i] = i;
        for(ll j = 2 * i; j <= 1e7; j += i) {
            if(Div[j] == -1) Div[j] = i;
        }
    }
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        vector<ll> v;
        while(a != 1) {
            v.push_back(Div[a]);
            a /= Div[a];
        }
        if(v.back() == v[0]) {
            ans[i] = {-1, -1};
        } else {
            ans[i] = {1, 1};
            for(auto val : v) {
                if(val == v[0]) {
                    ans[i].first *= val;
                } else {
                    ans[i].second *= val;
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        cout << ans[i].first << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        cout << ans[i].second << " ";
    }
    cout << endl;
    return 0;
}