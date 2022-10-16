#include <iostream>

using namespace std;
long long n, k, a[100009];
long long dp[1000009];
int main()
{
cin>>n>>k;

dp[1]=1;
for(long long i=2;i<=n;i++)
dp[i]=dp[i-1]+i;

for(long long i=1;i<=n;i++)
    cin>>a[i];

long long i=1;

while(k-i>0) k-=i, i++;

cout<<a[k]<<'\n';

    return 0;
}