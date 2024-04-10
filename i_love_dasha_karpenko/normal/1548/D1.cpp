#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 6e3+7;
const int MOD = 4;
pair<int,int> A[N];
int cnt[3][3];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i].first>>A[i].second;
        //A[i].first&=3;
        //A[i].second&=3;
        cnt[A[i].first%MOD][A[i].second%MOD]++;
    }
    ll res = 0;
    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            int dx = abs(A[i].first-A[j].first),dy = abs(A[i].second-A[j].second);
            int g = __gcd(dx%MOD,dy%MOD)%MOD;
            if (g==4 || g==0){
                res+=n-2;
            }
            else{
                res+=cnt[A[i].first%MOD][A[i].second%MOD]-1+cnt[A[j].first%MOD][A[j].second%MOD]-1;
            }
        }
    }
    cout<<res/3<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}