#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
string vowl = "aiueo";

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    int n = -1;
    int m = -1;
    for(int i = 5; i * 5 <= k; i++) {
        if(k % i != 0) continue;
        n = i;
        m = k / i;
    }
    if(n == -1) {
        cout << -1 << endl;
        return 0;
    }
    string ret;
    for(int i = 0; i < k; i++) {
        int h = i / n;
        int w = i % n;
        ret.push_back(vowl[(h + w) % 5]);
    }
    cout << ret << endl;
    return 0;
}