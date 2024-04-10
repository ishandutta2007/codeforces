#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % k != 0) {
        cout << "No" << endl;
        return 0;
    }
    int ave = sum / k;
    vector<int> ans;
    int cnt = 0;
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        tmp += a[i];
        cnt++;
        if(ave == tmp) {
            ans.push_back(cnt);
            cnt = 0;
            tmp = 0;
        } else if(ave < tmp) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(ans.size() != k) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}