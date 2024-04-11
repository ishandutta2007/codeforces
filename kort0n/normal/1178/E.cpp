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
string S;
string ans;
char center = '#';
int main() {
    //cout.precision(10);
    cin >> S;
    int l = 0;
    int r = S.size() - 1;
    while(true) {
        if(r < l) break;
        if(r - l <= 2) {
            center = S[l];
            break;
        }
        bool added = false;
        for(int i = 0; i <= 1; i++) {
            for(int j = 0; j <= 1; j++) {
                if(added) break;
                if(S[l+i] == S[r-j]) {
                    ans.push_back(S[l+i]);
                    added = true;
                }
            }
        }
        l += 2;
        r -= 2;
    }
    cout << ans;
    if(center != '#') cout << center;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}