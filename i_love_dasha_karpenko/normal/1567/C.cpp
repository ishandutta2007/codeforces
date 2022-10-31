//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gt(tuple,el) (get<el>(tuple))
const int N = 20;
ll dp[N][2][2],A[N],cnt[N];
void solve(){
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    dp[0][0][0] = 1;
    for(int i = 0;i<N;++i){
        A[i] = n%10;
        n/=10;
    }
    for(int i = 0;i<14;++i){
        for(int cur = 0;cur<=1;++cur){
            for(int nxt = 0;nxt<=1;++nxt){
                {
                    int need = A[i]-cur;
                    if (need>=0 && need<N)
                    dp[i+1][nxt][0] += dp[i][cur][nxt]*cnt[need];
                }
                {
                    int need = A[i]+10-cur;
                    if (need>=0 && need<N)
                    dp[i+1][nxt][1] += dp[i][cur][nxt]*cnt[need];
                }
            }
        }
    }
    ll res = dp[13][0][0];
    cout<<res-2<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for(int i = 0;i<10;++i){
        for(int j = 0;j<10;++j)
            cnt[i+j]++;
    }
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}