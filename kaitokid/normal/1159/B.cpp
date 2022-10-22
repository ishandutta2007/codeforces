#include <bits/stdc++.h>
using namespace std;
int n,ans=1000000009;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
int x,s;
for(int i=0;i<n;i++){cin>>x;s=max(i,n-1-i);ans=min(ans,x/s);}
cout<<ans;
return 0;
}