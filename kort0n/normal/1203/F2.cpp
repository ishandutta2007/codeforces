#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef pair<int, i_i> iii;
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
int a[105], b[105];
int r;
int ans = 0;
int dp[60050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> r;
    vector<i_i> v;
    vector<iii> w;
    for(int i = 1; i <= N; i++) {
        cin >> a[i] >> b[i];
        if(b[i] >= 0) v.push_back({a[i], b[i]});
        else w.push_back({-b[i] - max(a[i], -b[i]), {-b[i], a[i]}});
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    for(int i = 0; i < v.size(); i++) {
        if(v[i].first <= r) {
            r += v[i].second;
            ans++;
        }
    }
    for(int val = 0; val <= 6e4; val++) {
        if(val <= r) dp[val] = ans;
        else dp[val] = -1e9;
    }
    for(int i = 0; i < w.size(); i++) {
        int a = w[i].second.second;
        int b = w[i].second.first;
        //cerr << r << " " << a << " " << b << endl;
        /*
        if(a <= r && r - b >= 0) {
            r -= b;
            ans++;
        }
        */
       for(int i = max(a, b); i <= 6e4; i++) {
           chmax(dp[i-b], dp[i] + 1);
       }
    }
    for(int i = 0; i <= 6e4; i++) {
        chmax(ans, dp[i]);
    }
    cout << ans << endl;
    /*
    if(ans == N) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    //*/
    return 0;
}