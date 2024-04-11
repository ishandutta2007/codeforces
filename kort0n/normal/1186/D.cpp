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

#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
const long double EPS = 1e-7;
long double a[100500];
bool can[100500];
ll b[100500];
ll sum = 0;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        b[i] = (ll)a[i];
        if(a[i] < EPS) {
            if(abs(a[i] - (long double)b[i]) > EPS) b[i]--;
        }
        if(abs(a[i] - (long double)b[i]) <= EPS) can[i] = false;
        else can[i] = true;
        sum += b[i];
        //cerr << i << " " << b[i] << " " << can[i] << endl;
    }
    for(int i = 1; i <= N; i++) {
        if(sum == 0) continue;
        if(!can[i]) continue;
        b[i]++;
        sum++;
    }
    for(int i = 1; i <= N; i++) printf("%lld\n", b[i]);
    return 0;
}