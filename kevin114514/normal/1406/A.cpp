#include<bits/stdc++.h>
using namespace std;
int app[110];
int main()
{
int t;
cin>>t;
while(t--)
{
memset(app,0,sizeof(app));
int n;
cin>>n;
for(int i=0;i<n;i++)
{
int x;
cin>>x;
app[x]++;
}
int ans=0;
int delta=2;
for(int i=0;delta;i++)
{
if(app[i]<delta)
{
delta--;
ans+=i;
i--;
}
}
cout<<ans<<endl;
}
return 0;
}