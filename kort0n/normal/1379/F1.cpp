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
ll a[201000], b[201000];
set<ll> row[401000], column[401000];
ll H, W, Q;

bool g() {
    ll Up = 2 * H - 1;
    ll Down = 0;
    ll Right = 2 * W - 1;
    ll Left = 0;
    ll maxi, mini;
    while(true) {
        //cerr << Up << " " << Down << " " << Right << " " << Left << endl;
        if(Up < Down) return true;
        if(Right < Left) return true;
        if(row[Up].empty()) {
            Up -= 2;
            continue;
        }
        auto itr = row[Up].end();
        itr--;
        maxi = *itr;
        mini = *(row[Up].begin());
        if(maxi < Left or mini > Right) {
            Up -= 2;
            continue;
        }
        if(row[Down].empty()) {
            Down += 2;
            continue;
        }
        itr = row[Down].end();
        itr--;
        maxi = *itr;
        mini = *(row[Down].begin());
        if(maxi < Left or mini > Right) {
            Down += 2;
            continue;
        }
        if(column[Right].empty()) {
            Right -= 2;
            continue;
        }
        itr = column[Right].end();
        itr--;
        maxi = *itr;
        mini = *(column[Right].begin());
        if(maxi < Down or mini > Up) {
            Right -= 2;
            continue;
        }
        if(column[Left].empty()) {
            Left += 2;
            continue;
        }
        itr = column[Left].end();
        itr--;
        maxi = *itr;
        mini = *(column[Left].begin());
        if(maxi < Down or mini > Up) {
            Left += 2;
            continue;
        }
        return false;
    }
}

bool f(ll q) {
    //cerr << "----" << q << "----" << endl;
    for(int i = 0; i <= 4e5; i++) {
            row[i].clear();
            column[i].clear();
    }
    for(int i = 0; i <= q; i++) {
        row[a[i]].insert(b[i]);
        column[b[i]].insert(a[i]);
    }
    return g();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    ll ok = -1;
    ll ng = Q;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    for(int i = 0; i <= ok; i++) cout << "YES" << endl;
    for(int i = ok + 1; i < Q; i++) cout << "NO" << endl;
    return 0;
}