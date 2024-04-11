#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
vector<int> S;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    S.resize(n);
    for(int i = 0; i < n; i++) cin >> S[i];
    sort(S.begin(), S.end(), greater<ll>());
    int x = 20;
    vector<int> ansindex;
    while(true) {
        x--;
        ansindex.clear();
        vector<int> independent;
        for(int i = 0; i < n; i++) {
            if(S[i] >= (1 << x)) continue;
            int val = S[i];
            for(int j = 0; j < independent.size(); j++) {
                val = min(val, val ^ independent[j]);
            }
            if(val == 0) continue;
            independent.push_back(val);
            ansindex.push_back(i);
            sort(independent.begin(), independent.end(), greater<ll>());
        }
        if(ansindex.size() == x) break;
    }
    cout << x << endl;
    for(int bits = 0; bits < (1 << x); bits++) {
        int nowbit = bits ^ (bits >> 1);
        int now = 0;
        for(int j = 0; j < x; j++) {
            if(1 & (nowbit >> j)) now ^= S[ansindex[j]];
        }
        cout << now;
        if(bits + 1 != (1 << x)) cout << " ";
    }
    cout << endl;
    return 0;
}