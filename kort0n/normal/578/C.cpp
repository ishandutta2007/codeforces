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
ll N;
double a[200050];

double f(double x) {
    double ret = 0.0;
    double maxi = 0.0;
    double mini = 0.0;
    for(int i = 1; i <= N; i++) {
        double now = a[i] - x;
        maxi += now;
        mini += now;
        chmax(maxi, 0.0);
        chmin(mini, 0.0);
        chmax(ret, maxi);
        chmax(ret, -mini);
    }
    //cerr << x << " " << ret << endl;
    return ret;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    double ok = 1e4;
    double ng = -1e4;
    for(int _ = 1; _ <= 100; _++) {
        double b = (ok * 2 + ng) / 3;
        double c = (ok + ng * 2) / 3;
        if(f(b) < f(c)) ng = c;
        else ok = b;
    }
    cout << fixed << setprecision(15) << f(ok) << endl;
    return 0;
}