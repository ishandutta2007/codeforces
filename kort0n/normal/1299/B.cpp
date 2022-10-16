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
int N;
int x[100000], y[100000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    if(N % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
    for(int i = 0; i < N / 2; i++) {
        int dx1 = x[i+1] - x[i];
        int dy1 = y[i+1] - y[i];
        int dx2 = x[(N/2+i+1) % N] - x[N/2+i];
        int dy2 = y[(N/2+i+1) % N] - y[(N/2+i) % N];
        if(dx1 != -dx2 or dy1 != -dy2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}