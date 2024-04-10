#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return ((ll)a*b)%MOD;
}

int dp[105][2505];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    dp[0][0] = 1;
    for(int len=1; len<=100; len++){
        for(int sum=0; sum<=25*len; sum++){
            for(int tren=0; tren<=min(25, sum); tren++){
                dp[len][sum] = add(dp[len][sum], dp[len-1][sum-tren]);
            }
        }
    }
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += s[i] - 'a';
        }
        cout << dp[n][sum]-1 << "\n";
    }
    return 0;
}