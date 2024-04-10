#include <bits/stdc++.h> 
using namespace std ;
int a[100009],b[100009];
int n,m,k;
 int main(){
ios::sync_with_stdio(0);
int ans=-1;
cin>>n>>k>>m;
for(int i=0;i<n;i++)
{
cin>>a[i];
b[a[i]%m]++;
if(b[a[i]%m]==k)ans=a[i]%m;}
if(ans==-1){cout<<"No";return 0;}
cout<<"Yes\n";
int i=0,v=0;
while(v<k)
{

if(a[i]%m==ans){cout<<a[i]<<" ";v++;}
i++;

}
return 0;}