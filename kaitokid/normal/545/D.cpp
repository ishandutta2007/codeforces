#include <bits/stdc++.h>
using namespace std;
long long n,a[100009];
int main(){
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
int ans=1;
long long time=a[0];
for(int i=1;i<n;i++)
{
if(time<=a[i]){ans++;time+=a[i];}


}
cout<<ans;
return 0;}