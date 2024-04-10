#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(vec) vec.begin(),vec.end()
#define endl '\n'
vector< pair< pair<int,int> ,pair<int,int> > > ans;
const int N = 207;
const ll INF = 1e18+7;
ll A[N][N];
ll dp[N][N],mid[N][N];
int P[N];
void calc(int l,int r){
    if (r-l<1) return;
    P[mid[l][mid[l][r]-1]] = mid[l][r];
    P[mid[mid[l][r]+1][r]] = mid[l][r];
    calc(l,mid[l][r]-1);
    calc(mid[l][r]+1,r);
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=n;++j) {
            cin >> A[i][j];
            A[i][j] += A[i][j-1];
        }
    for(int len = 1;len<=n;++len)
    for(int l = 1;l+len-1<=n;++l){
        int r = l+len-1;
        dp[l][r] = INF;
        ll lift_sum = 0;
        for(int i = l;i<=r;++i)
            lift_sum += A[i][n]-A[i][r]+A[i][l-1];
        for(int mid = l;mid<=r;++mid){
            if (dp[l][r]>dp[l][mid-1]+dp[mid+1][r]+lift_sum){
                dp[l][r] = dp[l][mid-1]+dp[mid+1][r]+lift_sum;
                ::mid[l][r] = mid;
            }
        }
    }
    calc(1,n);
    for(int i = 1;i<=n;++i)
        cout<<P[i]<<' ';
    cout<<endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}