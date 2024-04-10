#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
int n,k;
cin>>n>>k;
for(int i=1;i<=n;i++)
{
    if(n%i!=0)continue;
    int x=i*k;
    int y=n/i;
    if(y>=k)continue;
    cout<<x+y;
    return 0;
}
    return 0;
}