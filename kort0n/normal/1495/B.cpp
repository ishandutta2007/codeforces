#include <bits/stdc++.h>
//#include <atcoder/all>
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
ll p[105000];
vector<ll> v;
map<ll, l_l> mp;
ll len = 0;

void f(ll idx) {
    ll L = 0;
    ll R = 0;
    ll tmp = idx;
    while(tmp - 1 >= 0 and p[tmp-1] < p[tmp]) tmp--;
    L = idx - tmp;
    tmp = idx;
    while(tmp + 1 < N and p[tmp+1] < p[tmp]) tmp++;
    R = tmp - idx;
    if(L < R) swap(L, R);
    mp[idx] = {L, R};
    chmax(len, L);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < N; i++) {
        if(i >= 1 and p[i-1] > p[i]) continue;
        if(i + 1 < N and p[i+1] > p[i]) continue;
        v.push_back(i);
    }
    for(auto idx : v) {
        f(idx);
        //cerr << idx << " " << mp[idx].first << " " << mp[idx].second << endl;
    }
    ll ans = 0;
    ll num = 0;
    for(auto idx : v) {
        if(mp[idx].first < len) continue;
        l_l tmp = mp[idx];
        num++;
        if(tmp.second <= 1) continue;
        if(tmp.first > tmp.second + 1) continue;
        if(tmp.first == tmp.second) {
            if(tmp.first % 2 == 0) ans++;
            continue;
        }
    }
    if(num >= 2) ans = 0;
    cout << ans << endl;
    return 0;
}