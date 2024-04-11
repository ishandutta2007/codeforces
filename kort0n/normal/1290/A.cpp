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

int N, M, K;
int a[4500];
int b[4500];
int csum[4000];
int c[4500];

bool f(int border) {
    //cerr << "------" << border << "---------" << endl;
    for(int i = 0; i < N; i++) {
        if(a[i] >= border) b[i] = 1;
        else b[i] = 0;
    }
    for(int i = 0; i < N; i++) {
        if(N-(M-i) < N) c[i] = max(b[i], b[N - (M - i)]);
        else c[i] = 0;
        //cerr << i << " " << N - (M - i) << endl;
    }
    for(int i = 1; i <= N; i++) {
        csum[i] = csum[i-1] + c[i-1];
    }
    /*
    for(int i = 0; i <= N; i++) {
        cerr << c[i] << " ";
    }
    cerr << endl;
    */
    bool clear = false;
    for(int up = 0; up <= K; up++) {
        int down = K - up;
        int rest = M - 1 - K;
        if(csum[up+rest+1]-csum[up] == rest + 1) clear = true;
    }
    return clear;
}

void solve() {
    cin >> N >> M >> K;
    chmin(K, M - 1);
    for(int i = 0; i < N; i++) cin >> a[i];
    int ok = 0;
    int ng = 1e9 + 1;
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}