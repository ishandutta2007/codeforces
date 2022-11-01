#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    vector<ll> sum(n + 1);
    REP(i, n) sum[i + 1] = sum[i] + a[i]; 
    int q;
    cin >> q;
    map<ll, ll> memo;
    REP(_, q){
        ll k;
        ll cur = 0;
        ll times = 0;
        ll size = 1;
        ll ans = 0;
        cin >> k;
        if(memo.count(k)){
            cout << memo[k];
            goto END;
        }
        while(cur < n){
            ans += (sum[min(cur + size, (ll)n)] - sum[cur]) * times;
            times ++;
            cur += size;
            size *= k;
        }
        memo[k] = ans;
        cout << ans;
END:
        if(_ == q - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}