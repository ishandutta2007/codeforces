#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int a[107];
int main()
{
int u=0,n;
cin>>n;
for(int i=0;i<n;i++)
{cin>>a[i];
}
if(a[0]%2==0||a[n-1]%2==0){cout<<"No";return 0;}
if(n%2==1){cout<<"Yes";return 0;}
cout<<"No";
return 0;
}