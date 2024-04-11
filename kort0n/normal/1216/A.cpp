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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    int ans = 0;
    string S;
    cin >> N >> S;
    for(int i = 0; i < S.size(); i += 2) {
        if(S[i] == S[i+1]) {
            if(S[i] == 'a') S[i] = 'b';
            else S[i] = 'a';
            ans++;
        }
    }
    cout << ans << endl;
    cout << S << endl;
    return 0;
}