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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 2) {
        cout << 1 << endl;
        return 0;
    }
    vector<l_l> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    ll delta = v[1].first - v[0].first;
    int delition = -1;
    bool clear = true;
    for(int i = 1; i < n; i++) {
        if(delition == i - 1) {
            if(v[i-2].first + delta == v[i].first) continue;
            clear = false;
        }
        if(v[i-1].first + delta == v[i].first) continue;
        if(delition != -1) clear = false;
        delition = i;
    }
    if(clear) {
        if(delition == -1) delition = n - 1;
        cout << v[delition].second << endl;
        return 0;
    }
    clear = true;
    delta = v[2].first - v[1].first;
    for(int i = 3; i < n; i++) {
        if(v[i-1].first + delta != v[i].first) clear = false;
    }
    if(clear) {
       cout << v[0].second << endl;
       return 0;
    }
    clear = true;
    delta = v[2].first - v[0].first;
    for(int i = 3; i < n; i++) {
        if(v[i-1].first + delta != v[i].first) clear = false;
    }
    if(clear) {
       cout << v[1].second << endl;
       return 0;
    }
    cout << -1 << endl;
    return 0;
}