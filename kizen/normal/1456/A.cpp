#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e9 + 7;
const LL NS = (LL)1e5 + 4;
LL N, x, y, p, k;
char a[NS];
LL cnt[NS];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL T; cin >> T;
    while(T--){
        cin >> N >> p >> k;
        cin >> (a + 1);
        cin >> x >> y;
        for(LL i = N; i >= 1; --i){
            if(a[i] == '0'){
                ++cnt[i];
            }
            if(i + k <= N){
                cnt[i] += cnt[i + k];
            }
        }
        LL ans = (LL)MOD * MOD;
        for(LL i = p; i <= N; ++i){
            ans = min(ans, (i - p) * y + cnt[i] * x);
        }
        for(int i = 1; i <= N; ++i){
            cnt[i] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}