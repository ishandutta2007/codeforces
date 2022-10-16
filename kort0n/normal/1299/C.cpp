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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
ll N;
ll a[1000000];
vector<l_l> ans;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) {
        l_l now = {a[i], 1};
        while(!ans.empty()) {
            l_l tmp = ans.back();
            if(tmp.first * now.second < tmp.second * now.first) break;
            now = {now.first + tmp.first, now.second + tmp.second};
            ans.pop_back();
        }
        ans.push_back(now);
    }
    for(auto tmp : ans) {
        for(int i = 0; i < tmp.second; i++) {
            cout << fixed << setprecision(30) << (long double)tmp.first / tmp.second << "\n";
        }
    }
    return 0;
}