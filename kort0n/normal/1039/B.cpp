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
ll N, K;
const int LOCAL = 0;
ll l, r;
ll ans;
string ret;

void ask2();

void ask() {
    if(abs(r - l) <= 44) {
        ask2();
        return;
    }
    ll d = (r - l) / 2;
    ll mid = l + d;
    cout << l << " " << mid << endl;
    if(LOCAL) {
        if(ans <= mid) ret = "Yes";
        else ret = "No";
    } else {
        cin >> ret;
    }
    if(ret == "Bad") exit(0);
    if(ret == "Yes") {
        r = mid;
    } else {
        l = mid + 1;
    }
    l -= K;
    r += K;
    chmax(l, 1LL);
    chmin(r, N);
    if(LOCAL) {
        random_device seed_gen;
        default_random_engine engine(seed_gen());
        uniform_int_distribution<> dist(-K, K);
        ans += dist(engine);
        chmax(ans, 1LL);
        chmin(ans, N);
    }
}

void ask2() {
    random_device seed_gen;
    default_random_engine engine(seed_gen());
    int d = r - l;
    uniform_int_distribution<ll> dist(0, d);
    ll delta = dist(engine);
    ll q = l + delta;
    chmin(q, N);
    chmax(q, 1LL);
    cout << q << " " << q << endl;
    if(LOCAL) {
        if(q == ans) ret = "Yes";
        else ret = "No";
    } else {
        cin >> ret;
    }
    if(ret == "Bad") exit(0);
    if(ret == "Yes") exit(0);
    else {
        l -= K;
        r += K;
        chmin(r, N);
        chmax(l, 1LL);
    }
    if(LOCAL) {
        random_device seed_gen;
        default_random_engine engine(seed_gen());
        uniform_int_distribution<> dist(-K, K);
        ans += dist(engine);
        chmax(ans, 1LL);
        chmin(ans, N);
    }
}

int main() {
    cin >> N >> K;
    l = 1;
    r = N;
    if(LOCAL) ans = (rand() % N) + 1;
    while(true) {
        ask();
    }
    return 0;
}