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
ll w[1050000];
ll wo[1050000];
ll wow[1050000];

int main() {
    //cout.precision(10);
    string S;
    cin >> S;
    S = "#" + S;
    for(int i = 1; i < S.size(); i++) {
        w[i] = w[i-1];
        wo[i] = wo[i-1];
        wow[i] = wow[i-1];
        if(S.substr(i, 2) == "vv") {
            w[i]++;
            wow[i] += wo[i-1];
            continue;
        } if(S[i] == 'o') {
            wo[i] += w[i];
        }
    }
    cout << wow[S.size() - 1] << endl;
    return 0;
}