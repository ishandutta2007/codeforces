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

ll anstwo[26][26];
ll num[26];
ll field[105000];

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = S.size();
    for(int i = 0; i < N; i++) {
        field[i] = (int)(S[i] - 'a');
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 26; j++) {
            anstwo[j][field[i]] += num[j];
        }
        num[field[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i < 26; i++) {
        chmax(ans, num[i]);
        for(int j = 0; j < 26; j++) {
            chmax(ans, anstwo[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}