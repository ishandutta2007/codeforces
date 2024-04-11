#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
//const ll mod = 1000000007;
vector<int> ans;
void solve() {
    ll N;
    cin >> N;
    if(N <= 3) {
        cout << -1 << endl;
        return;
    }
    ans.clear();
    int Last = 0;
    for(int i = 0; N - i >= 8; i += 4) {
        ans.push_back(i + 1);
        ans.push_back(i + 3);
        ans.push_back(i + 0);
        ans.push_back(i + 2);
        Last = i + 4;
    }
    if(N % 4 == 0) {
        ans.push_back(Last + 1);
        ans.push_back(Last + 3);
        ans.push_back(Last + 0);
        ans.push_back(Last + 2);
    } else if(N % 4 == 1) {
        ans.push_back(Last + 1);
        ans.push_back(Last + 3);
        ans.push_back(Last + 0);
        ans.push_back(Last + 2);
        ans.push_back(Last + 4);
    } else if(N % 4 == 2) {
        ans.push_back(Last + 1);
        ans.push_back(Last + 5);
        ans.push_back(Last + 3);
        ans.push_back(Last + 0);
        ans.push_back(Last + 2);
        ans.push_back(Last + 4);
    } else if(N % 4 == 3) {
        ans.push_back(Last + 1);
        ans.push_back(Last + 5);
        ans.push_back(Last + 3);
        ans.push_back(Last + 0);
        ans.push_back(Last + 2);
        ans.push_back(Last + 4);
        ans.push_back(Last + 6);
    }
    for(auto val : ans) {
        cout << val + 1 << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}