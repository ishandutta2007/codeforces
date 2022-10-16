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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int ans = 0;
    for(int i = 0; i < S.size(); i++) {
        int mini = 0;
        int maxi = 0;
        for(int j = i; j < S.size(); j++) {
            if(S[j] == '(') {
                mini++;
                maxi++;
            }
            if(S[j] == '?') {
                maxi++;
                mini--;
                if(mini < 0) mini = 1;
            }
            if(S[j] == ')') {
                mini--;
                maxi--;
                if(mini < 0) mini += 2;
            }
            if(maxi < 0) break;
            if((j-i)%2==1) {
                if(mini == 0) {
                    //cerr << i << " " << j << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}