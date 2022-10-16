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
typedef __int128_t bigint;
ll N, K;
vector<ll> a;
vector<ll> ans;

bigint g(bigint a, bigint b) {
    return b * (a - b * b);
}

vector<ll> f(bigint border) {
    vector<ll> ret(N);
    for(int i = 0; i < N; i++) {
        ll ok = 0;
        ll ng = a[i] + 1;
        while(abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            //cerr << i << " " << mid << endl;
            if(g(a[i], mid) - g(a[i], mid - 1) >= border) ok = mid;
            else ng = mid;
        }
        ret[i] = ok;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    priority_queue<l_l> que;
    a.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    bigint ng = -1e30;
    bigint ok = 1e30;
    //bigint ng = -10;
    //bigint ok = 10;
    while(ok - ng > 1) {
        bigint mid = (ok + ng) / 2;
        //cerr << (ll)mid << endl;
        vector<ll> tmp = f(mid);
        /*
        for(auto val : tmp) {
            cerr << val << " ";
        }
        */
        //cerr << endl;
        ll num = 0;
        for(auto val : tmp) num += val;
        if(num <= K) ok = mid;
        else ng = mid;
    }
    vector<ll> tmp1 = f(ok);
    vector<ll> tmp2 = f(ok - 1);
    /*
    for(auto tmp : out1) {
        cerr << tmp << " ";
    }
    cerr << endl;
    for(auto tmp : out2) {
        cerr << tmp << " ";
    }
    cerr << endl;
    */
    ll rest = K;
    for(int i = 0; i < N; i++) {
        rest -= tmp1[i];
    }
    for(int i = 0; i < N; i++) {
        ll delta = min(rest, tmp2[i] - tmp1[i]);
        rest -= delta;
        tmp1[i] += delta;
    }
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << tmp1[i];
    }
    cout << endl;
    return 0;
}