#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif
const int N = 100005;
int lst[2][N];
int dp[N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string A, B;
        cin >>  A>> B;
        lst[0][n] = lst[1][n] = n;
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            lst[0][i] = (A[i] == '0' || B[i] == '0') ? i : lst[0][i + 1];
            lst[1][i] = (A[i] == '1' || B[i] == '1') ? i : lst[1][i + 1];
            if(lst[0][i] == lst[1][i]){
                dp[i] = dp[i + 1] + 2;
            } else{
                if(lst[0][i] < lst[1][i]){
                    dp[i] = dp[i + 1] + 1;
                    if(lst[1][i] != n){
                        dp[i] = max(dp[i], dp[lst[1][i] + 1] + 2);
                    }
                } else{
                    dp[i] = 0;
                    if(lst[0][i] != n) dp[i] = max(dp[i], dp[lst[0][i] + 1] + 2);
                }
            }
            // if(n==2)    trace(lst[0][i], lst[1][i], i, dp[i]);
        }
        cout << dp[0] << endl;
        // if(dp[0] == 1) trace(dp[1]);
    }
}