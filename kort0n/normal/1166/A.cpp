#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
map<char, int> mp;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--) {
        string in;
        cin >> in;
        mp[in[0]]++;
    }
    int ans = 0;
    for(char moji = 'a'; moji <= 'z'; moji++) {
        int a = mp[moji] / 2;
        int b = mp[moji] - a;
        ans += a * (a - 1) / 2;
        ans += b * (b - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}