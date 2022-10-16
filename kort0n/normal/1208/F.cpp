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
vector<int> dp[5050000];
int MAX = 2000000;
int N;
int a[2050000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        dp[a[i]].push_back(i);
    }
    for(int i = 0; i <= MAX; i++) {
        sort(dp[i].begin(), dp[i].end(), greater<int>());
        if(dp[i].size() >= 3) dp[i].resize(2);
    }
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < (1 << 21); j++) {
            if(!(j & (1 << i))) {
                int before = (j | (1 << i));
                for(int k = 0; k < dp[before].size(); k++) {
                    dp[j].push_back(dp[before][k]);
                }
                sort(dp[j].begin(), dp[j].end(), greater<int>());
                dp[j].erase(unique(dp[j].begin(), dp[j].end()), dp[j].end());
                if(dp[j].size() >= 3) dp[j].resize(2);
            }
        }
    }
    /*
    for(int val = 0; val <= MAX; val++) {
        if(dp[val].size() >= 1) {
            cerr << "----" << val << "----" << endl;
            for(int i = 0; i < dp[val].size(); i++) cerr << dp[val][i] << " ";
            cerr << endl;
        }
    }
    */
    /*
    for(int val = MAX; val >= 0; val--) {
        sort(dp[val].begin(), dp[val].end(), greater<int>());
        dp[val].erase(unique(dp[val].begin(), dp[val].end()), dp[val].end());
        if(dp[val].size() >= 3) dp[val].resize(2);
        /*
        if(dp[val].size() >= 1) {
            cerr << "---" << val << "---" << endl;
            for(int j = 0; j < dp[val].size(); j++) {
                cerr << dp[val][j] << " ";
            }
            cerr << endl;
        }
        for(int i = 0; i < 20; i++) {
            if(val & (1 << i)) {
                for(int j = 0; j < dp[val].size(); j++) {
                    dp[val ^ (1 << i)].push_back(dp[val][j]);
                }
            }
        }
    }
    */
    int ans = 0;
    for(int bit = 20; bit >= 0; bit--) {
        for(int j = 1; j <= N; j++) {
            int now = ((ans | (1 << bit) ) & (~a[j]));
            if(dp[now].size() == 2 && dp[now].back() > j) ans |= (1 << bit);
        }
    }
    cout << ans << endl;
    return 0;
}