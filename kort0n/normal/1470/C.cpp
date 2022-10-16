#include <bits/stdc++.h>
//#include <atcoder/all>
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
random_device rd;
mt19937 mt(rd());
ll N, K;
ll idx;
ll ret;

void ask(int idx) {
    cout << "? " << idx + 1 << endl;
    cin >> ret;
}

void ANSWER(int idx) {
    cout << "! " << idx + 1 << endl;
}

int main() {
    string S = "eeroqqegimfefgrgiorgoi";
    cin >> N >> K;
    uniform_int_distribution<> test(0, N - 1);
    while(true) {
        idx = test(mt);
        ask(idx);
        if(ret != K) break;
    }
    while(ret != K) {
        if(ret < K) idx = (idx + 1) % N;
        else idx = (idx + N - 1) % N;
        ask(idx);
        if(ret == K) break;
    }
    ANSWER(idx);
    return 0;
}