#include<bits/stdc++.h>
using namespace std;
int x[110];
int main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
for(int i=0;i<n;i++)
cin>>x[i];
sort(x,x+n);
int ans=n;
for(int i=0;i<n;i++)
if(x[i]==x[0])
ans--;
cout<<ans<<endl;
}
return 0;
}