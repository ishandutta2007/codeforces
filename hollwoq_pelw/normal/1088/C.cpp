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

int main(){
    IOS;
    int n,t;
    cin >> n;
    int a[n];
    vector<pii> oop;
    int cur = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i > 0; i--){
        int k = i-1 - (a[i-1]+cur)%n;
        if (k < 0) k += n;
        if (k == 0) continue;
        cur = (cur+k)%n;
        oop.pb({i, k});
    }
    cout << oop.size() + 1 << endl;
    for (auto x:oop){
        cout << 1 << ' ' << x.F << ' ' << x.S << endl;
    }
    cout << 2 << ' ' << n << ' ' << n;
    
    
    return 0;
}