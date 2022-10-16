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
const ll INF = 1e17;
ll A[10][10];
string S;
ll dist[10][10];
void solve(int a, int b) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) dist[i][j] = INF;
    }
    for(int i = 0; i < 10; i++) {
        chmin(dist[i][(i+a)%10], (ll)1);
        chmin(dist[i][(i+b)%10], (ll)1);
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                chmin(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i + 1 < S.size(); i++) {
        ans += dist[(int)(S[i] - '0')][(int)(S[i+1]-'0')] - 1;
        chmin(ans, INF);
    }
    if(ans >= 99999999999999) ans = -1;
    A[a][b] = ans;
}

int main() {
    //cout.precision(10);
    cin >> S;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            solve(i, j);
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}