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
int n;
int a[105000];
int sum[3][105000];
int win[3];
vector<i_i> ans;
void solve(int t) {
    //cerr << "now: " << t << endl;
    win[1] = 0;
    win[2] = 0;
    int before = 0;
    int last = 0;
    while(before < n) {
        //cerr << t << " " << before << endl;
        if(sum[1][n] - sum[1][before] < t && sum[2][n] - sum[2][before] < t) return;
        int ok = n;
        int ng = before;
        while(ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if(sum[1][mid] - sum[1][before] >= t) ok = mid;
            else if(sum[2][mid] - sum[2][before] >= t) ok = mid;
            else ng = mid;
        }
        for(int i = 1; i <= 2; i++) {
            if(sum[i][ok] - sum[i][before] >= t) {
                last = i;
                win[i]++;
            }
        }
        before = ok;
    }
    if(win[last] > win[3-last]) {
        //cerr << "clear: " << t << endl;
        ans.emplace_back(win[last], t);
        //cerr << "B" << endl;
    }
    //cerr << "A" << endl;
    return;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[1][i] = sum[1][i-1];
        sum[2][i] = sum[2][i-1];
        sum[a[i]][i]++;
    }
    for(int t = 1; t <= n; t++) {
        solve(t);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}