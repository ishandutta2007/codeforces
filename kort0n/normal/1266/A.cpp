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

void solve() {
    string S;
    cin >> S;
    int even = 0;
    int zero = 0;
    int sum = 0;
    for(auto c : S) {
        if((int)(c - '0') % 2 == 0) even++;
        if(c == '0') zero++;
        sum += c - '0';
    }
    if(even >= 2 and zero >= 1 and sum % 3 == 0) {
        cout << "red" << endl;
    } else {
        cout << "cyan" << endl;
    }
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