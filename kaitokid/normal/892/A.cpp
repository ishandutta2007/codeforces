#include <bits/stdc++.h>
using namespace std;
vector<long long>a;
 int main()
{
int n;
long long sum=0,x;
cin>>n;
for(int i=0;i<n;i++)
{cin>>x;sum+=x;}
for(int i=0;i<n;i++)
{cin>>x;a.push_back(x);}
sort(a.begin(),a.end());
int v=a[n-1]+a[n-2];
if(v>=sum){cout<<"YES";return 0;}
cout<<"NO";
return 0;
}