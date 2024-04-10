#include <bits/stdc++.h>
using namespace std;
map<int,int> a;
int main()
{
ios::sync_with_stdio(0);
int n;
cin>>n;
int ans=0;
int x;
for(int i=0;i<n;i++)
{
cin>>x;
a[x]++;
ans=max(ans,a[x]);



}
cout<<ans;
return 0;}