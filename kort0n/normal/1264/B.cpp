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
ll Input[5];
ll num[5];
vector<ll> ans;

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

bool ok(int now) {
    for(int i = 1; i <= 4; i++) {
        num[i] = Input[i];
    }
    ans.clear();
    while(true) {
        if(now == 1) {
            if(num[2] == 0) break;
            ans.push_back(2);
            num[2]--;
            now = 2;
            continue;
        }
        if(now == 2) {
            if(num[1] != 0) {
                num[1]--;
                ans.push_back(1);
                now = 1;
                continue;
            }
            if(num[3] == 0) break;
            ans.push_back(3);
            now = 3;
            num[3]--;
            continue;
        }
        if(now == 3) {
            if(num[4] != 0) {
                num[4]--;
                ans.push_back(4);
                now = 4;
                continue;
            }
            if(num[2] == 0) break;
            ans.push_back(2);
            now = 2;
            num[2]--;
            continue;
        }
        if(now == 4) {
            if(num[3] == 0) break;
            ans.push_back(3);
            now = 3;
            num[3]--;
            continue;
        }
    }
    return ans.size() == N;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(ll i = 1; i <= 4; i++) {
        cin >> Input[i];
        N += Input[i];
    }
    for(int s = 1; s <= 4; s++) {
        if(ok(s)) {
            cout << "YES" << endl;
            for(auto val : ans) {
                cout << val - 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}