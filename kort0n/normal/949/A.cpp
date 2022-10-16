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
vector<int> ans[200500];
int zero = -1;
int one = -1;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    S = "#" + S;
    for(int i = 1; i < S.size(); i++) {
        if(S[i] == '0') {
            if(one >= 0) {
                ans[one].push_back(i);
                one--;
            } else {
                zero++;
                ans[zero].push_back(i);
            }
        } else {
            if(one == zero) {
                cout << -1 << endl;
                return 0;
            } else {
                one++;
                ans[one].push_back(i);
            }
        }
    }
    if(one != -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << zero + 1 << endl;
    for(int i = 0; i <= zero; i++) {
        cout << ans[i].size();
        for(auto val : ans[i]) cout << " " << val;
        cout << endl;
    }
    return 0;
}