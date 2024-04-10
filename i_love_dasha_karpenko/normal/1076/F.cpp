#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 3e5+7;
const int INF = 1e9+7;
int A[N][2],dp[N][2];
int up(int a,int b){
    if (a<0)
        return 0;
    return a/b+(a%b!=0);
}
void NO(){
    cout<<"NO\n";
    exit(0);
}
void solve(){
    int n,k;
    cin>>n>>k;
    for(int c = 0;c<2;++c)
        for(int i = 1;i<=n;++i)
            cin>>A[i][c];
    for(int i = 1;i<=n;++i){
        for(int c = 0;c<2;++c){
            if (A[i][c]<A[i][c^1]){
                if (up(A[i][c^1],k)>A[i][c]+1)
                    NO();
                if (up(A[i][c^1],k)==A[i][c]+1){
                    dp[i][c] = INF;
                    continue;
                }
                if (dp[i-1][c]<=k){
                    dp[i][c] = 1;
                }
                else if (dp[i-1][c^1]<=k){
                    if (up(A[i][c^1]-(k-dp[i-1][c^1]),k)+1>A[i][c]){
                        dp[i][c] = INF;
                    }
                    else
                        dp[i][c] = 1;
                }
                else {
                    dp[i][c] = INF;
                }
            }
            else if (A[i][c]==A[i][c^1]){
                if (k==1){
                    if (dp[i-1][c]>k)
                        dp[i][c] = INF;
                    else dp[i][c] = 1;
                }
                else{
                    if (dp[i-1][c]<=k || (dp[i-1][c^1]<=k && A[i][c^1]>1) || (dp[i-1][c^1]<k))
                        dp[i][c] = 1;
                    else dp[i][c] = INF;
                }
            }
            else{
                int l = 1,r = k+1;
                while(l!=r){
                    int tm = (l+r)>>1;
                    int flag = 0;
                    if (dp[i-1][c^1]<=k){
                        if (up(A[i][c]-tm,k)<=A[i][c^1])
                            flag = 1;
                    }
                    if (dp[i-1][c]<=k){
                        if (up(A[i][c]-tm-(k-dp[i-1][c]),k)+1<=A[i][c^1])
                            flag = 1;
                        if (dp[i-1][c]+A[i][c]<=tm)
                            flag = 1;
                    }
                    if (flag)
                        r = tm;
                    else l = tm+1;
                }
                int tm = l;
                int flag = 0;
                if (dp[i-1][c^1]<=k){
                    if (up(A[i][c]-tm,k)<=A[i][c])
                        flag = 1;
                }
                if (dp[i-1][c]<=k){
                    if (up(A[i][c]-tm-(k-dp[i-1][c]),k)+1<=A[i][c])
                        flag = 1;
                    if (dp[i-1][c]+A[i][c]<=tm)
                        flag = 1;
                }
                if (flag)
                    dp[i][c] = l;
                else dp[i][c] = INF;
            }
        }
    }
    if (dp[n][0]<=k || dp[n][1]<=k)
        cout<<"YES\n";
    else NO();
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();

    return 0;
}