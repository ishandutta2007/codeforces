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
int N;
int a[20000];
int b[20000];
bool ok[20000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        if(a[i] >= 0) {
            b[i] = a[i] / 2;
        } else {
            b[i] = (-a[i] + 1) / 2;
            b[i] = -b[i];
        }
        if((abs(a[i]) & 1)) ok[i] = true;
    }
    int sum = 0;
    for(int i = 1; i <= N; i++) sum += b[i];
    for(int i = 1; i <= N; i++) {
        if(sum == 0) break;
        if(ok[i]) {
            b[i]++;
            sum++;
        }
    }
    for(int i = 1; i <= N; i++) cout << b[i] << endl;
    return 0;
}