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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
string S;

void f(char in) {
    if(in == 'R') {
        for(int i = S.size() - 1; i >= 0; i--) {
            if(S[i] == '0') {
                S[i] = '1';
                return;
            }
        }
    }
    if(in == 'L') {
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '0') {
                S[i] = '1';
                return;
            }
        }
    }
    S[in - '0'] = '0';
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string T;
    cin >> N >> T;
    for(int i = 0; i < 10; i++) S.push_back('0');
    for(int i = 0; i < T.size(); i++) {
        f(T[i]);
    }
    cout << S << endl;
    return 0;
}