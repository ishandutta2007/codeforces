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

void solve() {
    string S;
    int N;
    cin >> N;
    cin >> S;
    int zeronum = 0;
    int onenum = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] != '0') break;
        zeronum++;
    }
    for(int i = S.size() - 1; i >= 0; i--) {
        if(S[i] != '1') break;
        onenum++;
    }
    for(int i = 0; i < zeronum; i++) cout << "0";
    if(onenum + zeronum != S.size()) cout << "0";
    for(int i = 0; i < onenum; i++) cout << "1";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    while(N--) solve();
    return 0;
}