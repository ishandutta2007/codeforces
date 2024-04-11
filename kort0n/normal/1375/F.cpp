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

const long long INF = 1e18;
//const ll mod = 1000000007;
ll ten(ll x) {
    ll ret = 1;
    while(x--) ret *= 10;
    return ret;
}

const ll LOCAL = 0;

ll Last = -1;
vector<ll> a(3);
ll turns = 0;
void ask(ll x) {
    turns++;
    assert(turns <= 1e5);
    cout << x << endl;
    if(LOCAL == 0 or LOCAL == 1) {
        cin >> Last;
        if(Last == 0) exit(0);
        Last--;
        a[Last] += x;
    } else {
        for(int i = 0; i < 3; i++) {
            if(i == Last) continue;
            a[i] += x;
            Last = i;
            return;
        }
    }
}

void DEBUG() {
    if(!LOCAL) return;
    for(auto val : a) {
        cerr << val << " ";
    }
    cerr << endl;
}

int main() {
    for(int i = 0; i < 3; i++) cin >> a[i];
    cout << "First" << endl;
    ask(ten(10));
    DEBUG();
    vector<ll> b = a;
    sort(b.begin(), b.end());
    ask(b[2] + b[2] - b[1] - b[0]);
    DEBUG();
    b = a;
    sort(b.begin(), b.end());
    ask(b[2] - b[1]);
    DEBUG();
    return 0;
}