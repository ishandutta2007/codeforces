#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int MOD=1e9 +7;
int a[400];
int main() {
ios::sync_with_stdio(0);
int t,n,k;
cin>>t;
int x;
while(t--)
{
cin>>n>>k;
for(int i=0;i<k;i++)
cin>>a[i];
sort(a,a+k);
int ans=max(a[0]-1,n-a[k-1]);
for(int i=1;i<k;i++)ans=max(ans,(a[i]-a[i-1])/2);
cout<<ans+1<<endl;
}
 return 0; }