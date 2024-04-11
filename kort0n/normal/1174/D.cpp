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
vector<int> v;
vector<int> ans;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int x;
    cin >> x;
    int outindex = 0;
    while(!((1 << outindex) & x)) outindex++;
    if(x >= (1 << n)) outindex = 20;
    v.push_back(0);
    for(int i = 1; i < (1 << n); i++) {
        if(i & (1 << outindex)) continue;
        v.push_back(i);
    }
    for(int i = 1; i < v.size(); i++) {
        ans.push_back(v[i-1] ^ v[i]);
    }
    cout << ans.size() << endl;
    if(ans.size() == 0) return 0;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    /*
    for(int i = 0; i < v.size(); i++) {
        cerr << v[i] << " ";
    }
    cerr << endl;
    */
    return 0;
}