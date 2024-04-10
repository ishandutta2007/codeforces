#include <bits/stdc++.h>

using namespace std;
bool u[200005];int n,ans,x;
int main()
{
    cin>>n;ans=n+1;
    for(int i=0;i<n;i++){cin>>x;if(!u[x]){u[x]=true;ans--;}}
    cout<<ans;
    return 0;
}