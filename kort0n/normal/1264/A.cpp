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

int N;

void solve() {
    cin >> N;
    map<ll, ll> mp;
    for(int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    vector<ll> v;
    for(auto val : mp) {
        v.push_back(val.second);
    }
    reverse(v.begin(), v.end());
    if(v.size() <= 3) {
        cout << "0 0 0" << endl;
        return;
    }
    ll g = v[0];
    int index = 1;
    ll s = 0;
    while(s <= g) {
        if(index == v.size()) {
            cout << "0 0 0" << endl;
            return;
        }
        s += v[index];
        index++;
    }
    ll b = 0;
    while(b <= g) {
        if(index == v.size()) {
            cout << "0 0 0" << endl;
            return;
        }
        b += v[index];
        index++;
    }
    if(s + g + b > N / 2) {
        cout << "0 0 0" << endl;
        return;
    }
    while(true) {
        if(s + g + b + v[index] > N / 2) break;
        b += v[index];
        index++;
    }
    cout << g << " " << s << " " << b << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}