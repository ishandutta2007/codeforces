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
int a[300050];
int dp[300050];
deque<i_i> deq;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i+N] = a[i];
        a[i+2*N] = a[i];
    }
    dp[3*N+1] = 2e9;
    for(int i = 3 * N; i >= 1; i--) {
        dp[i] = dp[i+1];
        while(!deq.empty()) {
            if(deq.back().first >= a[i]) {
                deq.pop_back();
            } else break;
        }
        deq.push_back({a[i], i});
        while(!deq.empty()) {
            if(deq.front().first * 2 < a[i]) {
                dp[i] = deq.front().second;
                deq.pop_front();
            } else break;
        }
    }
    for(int i = 1; i <= N; i++) {
        if(dp[i] >= 1e9) dp[i] = -1;
        else dp[i] -= i;
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}