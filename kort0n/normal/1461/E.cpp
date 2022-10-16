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

void YES() {
    cout << "Yes" << endl;
    exit(0);
}
void NO() {
    cout << "No" << endl;
    exit(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll l, k, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    k -= l;
    r -= l;
    l = 0;
    ll day = 0;
    ll now = k;
    set<ll> st;
    if(y >= x) {
    while(true) {
        ll delta = now / x;
        now -= x * delta;
        day += delta;
        if(day >= t) break;
        if(st.find(now) != st.end()) break;
        st.insert(now);
        now += y;
        if(now > r) {
            cout << "No" << endl;
            return 0;
        }
        if(now < x) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
    } else {
        ll now = k;
        ll lose = x - y;
        ll delta = (now - (r - y) + lose - 1) / lose;
        chmax(delta, 0LL);
        day += delta;
        now -= x * delta;
        //cerr << delta << " " << day << " " << now << endl;
        if(now < l) {
            if(day - 1 >= t) YES();
            else NO();
        }
        delta = now / lose;
        day += delta;
        now -= lose * delta;
        //cerr << delta << " " << day << " " << now << endl;
        while(true) {
            if(day >= t) YES();
            now += y;
            now -= x;
            day++;
            if(now < 0) NO();
        }
    }
}