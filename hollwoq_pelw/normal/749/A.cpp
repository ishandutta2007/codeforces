#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n) fixed << setprecision(n)

#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
// #define sz(a) a.size()

const int mod = 998244353, mod2 = 1e+7;

int n;
void solve(){
    cin >> n;
    bool od = 0;
    if (n%2) {od = 1; n -= 3;}
    cout << n/2+od << endl;
    for (int i = 0; i < n/2; i++){
        cout << 2 << ' ';
    }
    if (od) cout << 3;
}

int main(){
    IOS;
    
    solve();
    
    return 0;
}