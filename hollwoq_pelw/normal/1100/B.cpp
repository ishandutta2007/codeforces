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

int n,m,cur,a;

void solve(){
    cin >> n >> m;
    int cnt[n] = {0};
    for (int i = 1; i <= m; i++){
        cin >> a;
        cnt[a-1] ++;
        if (i >= (cur+1)*n){
            bool f = 1;
            for (int i = 0; i < n; i++){
                if (cnt[i] <= cur) {f = 0; break;}
            }
            if (f) {cout << '1'; cur++;}
            else cout << '0';
        }else cout << '0';
    }
    
}

int main(){
    IOS;
    solve();
    return 0;
}