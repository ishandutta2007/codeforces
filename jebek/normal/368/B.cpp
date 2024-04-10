#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,a[200000],dp[200000];
bool mark[200000];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=n-1;i>-1;i--)
    {
        dp[i]=dp[i+1];
        if(!mark[a[i]]){
            dp[i]++;
        }
        mark[a[i]]=true;
    }
    for(int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        cout<<dp[b-1]<<endl;
    }
}