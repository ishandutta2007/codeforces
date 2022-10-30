#include <bits/stdc++.h>

using namespace std;
typedef long ll;
typedef long double ld;
#define endl '\n'
#define x1 fgdfgdg
const ll DIM = 207;
const ll MAXCAP = 100*100*2;
const ll INF = 1E9;
const ll ADD = DIM*DIM;
pair<ll,ll> A[DIM];
ll dp[DIM][DIM*DIM*2],olddp[DIM][DIM*DIM*2],ans[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i) {
        cin >> A[i].first >> A[i].second;
        A[i].first*=2;
        A[i].second*=2;
    }
    for(ll cnt = 0;cnt<=n;++cnt){
        for(ll cap = 0;cap<=MAXCAP+ADD;++cap){
            olddp[cnt][cap] = dp[cnt][cap] = -INF;
        }
    }
    olddp[0][ADD] = 0;
    for(ll i = 1;i<=n;++i){
        for(ll cnt = 0;cnt<i;++cnt){
            for(ll cap = 0;cap<=MAXCAP+ADD;++cap){
                if (olddp[cnt][cap]==-INF)continue;
                ll rcap = cap-ADD;
                if (rcap<0 ){
                    if (rcap-A[i].first+A[i].second+ADD>=0)
                        dp[cnt+1][rcap-A[i].first+A[i].second+ADD] = max(dp[cnt+1][rcap-A[i].first+A[i].second+ADD],olddp[cnt][cap]+A[i].second);
                }
                else {
                    ll ncap = min(A[i].first - A[i].second, rcap);
                    ll left = A[i].first-A[i].second;
                    if (cap-left>=0)
                        dp[cnt + 1][cap - left] = max(dp[cnt + 1][cap - left], olddp[cnt][cap] + A[i].second + ncap);
                }
                if (rcap<0) {
                    ll ncap = min(A[i].second/2,-rcap);
                    if (cap+A[i].second/2<ADD*2)
                        dp[cnt][cap+A[i].second/2] = max(dp[cnt][cap+A[i].second/2], olddp[cnt][cap]+ncap);
                }
                else{
                    if (cap+A[i].second/2<ADD*2)
                        dp[cnt][cap + A[i].second/2] = max(dp[cnt][cap + A[i].second/2], olddp[cnt][cap]);
                }
            }
        }
        for(ll cnt = 0;cnt<=i;++cnt){
            for(ll cap = 0;cap<=MAXCAP+ADD;++cap){
                olddp[cnt][cap] = dp[cnt][cap];
                dp[cnt][cap] = -INF;
            }
        }
    }
    for(ll cnt = 1;cnt<=n;++cnt){
        for(ll cap = 0;cap<=MAXCAP+ADD;++cap){
            ans[cnt] = max(ans[cnt],olddp[cnt][cap]);
        }
        cout<<ans[cnt]/2;
        if (ans[cnt]%2)cout<<".5";
        cout<<' ';
    }
    return 0;
}