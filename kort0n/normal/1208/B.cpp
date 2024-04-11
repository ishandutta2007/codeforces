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
int a[2005];
map<int, int> mp;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    int r = 0;
    while(r < N) {
        if(mp[a[r+1]] == 0) {
            mp[a[r+1]]++;
            r++;
        } else break;
    }
    if(r == N) {
        cout << 0 << endl;
        return 0;
    }
    int l = 0;
    while(true) {
        if(mp[a[N-l]] == 0) {
            mp[a[N-l]]++;
            l++;
        } else break;
    }
    int ans = r + l;
        cerr << r << " " << l << endl;
    while(r >= 1) {
        mp[a[r]]--;
        r--;
        while(mp[a[N-l]] == 0) {
            mp[a[N-l]]++;
            l++;
        }
        //cerr << r << " " << l << endl;
        chmax(ans, r + l);
    }
    cout << N - ans << endl;
    return 0;
}