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

int n,m,k,s;
map<int, int> mp1, mp2;
vector<pii> a,b;

bool corr(int j){
    int x = b[j].F-a[0].F;
    if (x < 0) x+=m;
    for (int i = 0; i < s; i++){
        if (b[(i+j)%s].F != (a[i].F+x)%m || b[(i+j)%s].S != a[i].S) return 0;
    }
    return 1;
}

void solve(){
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {cin >> k; mp1[k] ++;}
    for (int i = 0; i < n; i++) {cin >> k; mp2[k] ++;}
    
    for (auto [p, v]:mp1) a.pb({p, v});
    for (auto [p, v]:mp2) b.pb({p, v});
    
    s = sz(a);
    int ans = INT_MAX;
    
    for (int i = 0; i < s; i ++){
        if(corr(i)){
            int x = b[i].F-a[0].F;
            if (x < 0) x+=m;
            ans = min(ans, x);
        }
    }
    cout << ans;
}

int main(){
    IOS;
    
    solve();
    
    return 0;
}