#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
bool clear = true;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    bitset<10001> s[60];
    for(int i = 1; i <= m; i++) {
        int len;
        cin >> len;
        while(len--) {
            int in;
            cin >> in;
            s[i][in] = 1;
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = i + 1; j <= m; j++) {
            bitset<10001> ret = s[i] & s[j];
            if(ret == s[0]) clear = false;
        }
    }
    if(clear) cout << "possible" << endl;
    else cout << "impossible" << endl;
    return 0;
}