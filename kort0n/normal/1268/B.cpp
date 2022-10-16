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
ll a[301000];
ll num = 0;
bool odd = false;

ll ans = 0;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= N; i++) {
        if(odd) chmin(num, (a[i] + 1) / 2);
        else chmin(num, a[i] / 2);
        ll before = 2 * num;
        if(odd) before--;
        ans += (a[i] - before) / 2;
        ans += num;
        //cerr << i << " " << num << endl;
        if((a[i] - before) % 2 == 0) {
            if(odd) {
                odd = false;
                num--;
            } else {
                odd = true;
            }
        } else {
            if(odd) {
                odd = false;
            } else {
                odd = true;
                num++;
            }
        }
        if(num == 0) odd = false;
    }
    cout << ans << endl;
    return 0;
}