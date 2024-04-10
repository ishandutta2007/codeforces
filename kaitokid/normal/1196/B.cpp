#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,x,sum;
ll a[200009];
int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)
{
cin>>n>>k;
ll l=0;
sum=0;
for(int i=0;i<n-1;i++)
{
cin>>x;
sum+=x;
if(sum%2==1 && l<k-1){a[l]=i;l++;sum=0;}
}
cin>>x;
sum+=x;
if(l!=k-1||sum%2==0){cout<<"NO\n";continue;}
cout<<"YES\n";
for(int i=0;i<l;i++)cout<<a[i]+1<<" ";
cout<<n<<endl;






}
return 0;
}