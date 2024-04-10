#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#define p 1000000007

typedef long long ll;

using namespace std;
ll n,k,d,dp[111][4];
int main()
{
    cin>>n>>k>>d;
    dp[0][0]=1;
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=k; j++){ 
            if(i<j)
                break;
            if(j<d){
                dp[i][0]+=dp[i-j][0];
                dp[i][0]%=p;
                dp[i][1]+=dp[i-j][1];
                dp[i][1]%=p;
            }
            else{
                dp[i][1]+=dp[i-j][0]+dp[i-j][1];
                dp[i][1]%=p;                
            }               
        }
    cout<<dp[n][1];
    
    return 0;
}