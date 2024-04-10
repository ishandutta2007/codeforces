#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
int a[100007];
int main()
{ios::sync_with_stdio(0);
int n,x;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;
int d=max(x-i,x-(n-i-1));
if(d>0)a[d]++;



}
sort(a,a+100007);
cout<<n-a[100006];
return 0;}