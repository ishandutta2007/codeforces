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
#define sz(a) a.size()

const int mod1 = 998244353, mod2 = 1e+7;

ld n,r,x;

void solve(){
    cin >> n >> r;
    x = sin(acos(-1.0)/n);
    cout << rnd(9) << (r*x)/(1-x);
}

int main(){
    IOS;
    solve();
    return 0;
}