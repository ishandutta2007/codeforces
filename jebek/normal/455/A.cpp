#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cstring>

#define X first
#define Y second
#define MP make_pair

using namespace std;

long long dp[1000000],n,t[1000000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        t[x]++;
    }
    dp[1]=t[1];
    for(int i=2;i<=100000;i++)
        dp[i]=max(dp[i-1],dp[i-2]+t[i]*i);
    cout<<dp[100000]<<endl;
}