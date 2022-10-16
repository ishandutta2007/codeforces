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
map<char, int> mp[205000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string S;
    cin >> S;
    S = "#" + S;
    for(int i = 1; i <= n; i++) {
        for(char moji = 'a'; moji <= 'z'; moji++) mp[i][moji] = mp[i-1][moji];
        mp[i][S[i]]++;
    }
    int m;
    cin >> m;
    while(m--) {
        string t;
        cin >> t;
        map<char, int> sub;
        for(int i = 0; i < t.size(); i++) sub[t[i]]++;
        int ok = n;
        int ng = 0;
        while(ok - ng > 1) {
            int mid = (ok + ng) / 2;
            bool clear = true;
            for(char moji = 'a'; moji <= 'z'; moji++) {
                if(sub[moji] > mp[mid][moji]) clear = false;
            }
            if(clear) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
    return 0;
}