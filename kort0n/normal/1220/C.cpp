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
string win = "z";

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    win[0]++;
    cin >> S;
    for(int i = 0; i < S.size(); i++) {
        string now;
        now.push_back(S[i]);
        if(win < now) cout << "Ann" << endl;
        else {
            cout << "Mike" << endl;
            chmin(win, now);
        }
    }
    return 0;
}