#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
int num[100050];
int maxi = 0;
int inv[100050];
int nonzero = 0;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    for(int time = 1; time <= n; time++) {
        int x;
        cin >> x;
        inv[num[x]]--;
        if(num[x] == 0) nonzero++;
        num[x]++;
        inv[num[x]]++;
        maxi = max(maxi, num[x]);
        if((inv[maxi] == 1) && (inv[maxi-1] == nonzero - 1)) ans = time;
        if((inv[maxi] == nonzero - 1) && (inv[1] == 1)) ans = time;
        if(inv[1] == nonzero) ans = time;
    }
    cout << ans << endl;
    return 0;
}