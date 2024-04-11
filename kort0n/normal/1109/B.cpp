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
bool IsPallindrome(string T) {
    string S =T;
    reverse(S.begin(), S.end());
    return S == T;
}

int f(string S) {
    if(S.size() % 2) return 2;
    string T = S.substr(0, S.size() / 2);
    if(!IsPallindrome(T)) return 1;
    return f(T);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    set<char> st;
    for(int i = 0; i < S.size() / 2; i++) {
        st.insert(S[i]);
    }
    if(st.size() <= 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << f(S) << endl;
    return 0;
}