#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v;

int main()
{

ios::sync_with_stdio(0);
 int n;
cin>>n;
if(n==1){int x;cin>>x;cout<<min(x-1,1000000-x);return 0;}
int x;
for(int i=0;i<n;i++)
{

cin>>x;
v.push_back(x);

}

int ans=10000000;
for(int i=0;i<n;i++)
ans=min(ans,max(v[i]-1,1000000-v[i+1]));
ans=min(ans,v[n-1]-1);
ans=min(ans,1000000-v[0]);
cout<<ans;
return 0;}