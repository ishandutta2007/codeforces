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
ll N, A[205000];
ll q;
ll ope[205000], p[205000], x[205000];
ll now;
ll B[205000];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> ope[i];
        if(ope[i] == 1) {
            cin >> p[i] >> x[i];
        } else {
            cin >> x[i];
        }
    }
    now = 0;
    for(int i = 1; i <= N; i++) B[i] = -1;
    for(int qu = q; qu >= 1; qu--) {
        if(ope[qu] == 1) {
            if(B[p[qu]] != -1) continue;
            B[p[qu]] = max(now, x[qu]);
        } else {
            chmax(now, x[qu]);
        }
    }
    for(int i = 1; i <= N; i++) {
        if(B[i] != -1) cout << B[i] << " ";
        else {
            cout << max(now, A[i]) << " ";
        }
    }
    cout << endl;
    return 0;
}