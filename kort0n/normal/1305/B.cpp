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
string S;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<ll> L, R;
    cin >> S;
    ll l = 0;
    ll r = S.size() - 1;
    while(l < r) {
        if(S[l] != '(') {
            l++;
            continue;
        }
        if(S[r] != ')') {
            r--;
            continue;
        }
        L.push_back(l);
        R.push_back(r);
        l++;
        r--;
    }
    if(L.empty()) {
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;
    cout << 2 * L.size() << endl;
    for(int i = 0; i < L.size(); i++) cout << L[i] + 1 << " ";
    for(int i = R.size() - 1; i >= 0; i--) {
        cout << R[i]+ 1 << " ";
    }
    cout << endl;
    return 0;
}