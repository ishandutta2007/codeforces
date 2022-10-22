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

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    int v[] = {100, 20, 10, 5, 1};
    for (auto g:v){
        ans += n/g;
        n %= g;
    }
    cout << ans;
}

int main(){
    IOS;
    solve();
    
    return 0;
}