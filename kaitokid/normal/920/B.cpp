#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int MOD=1e9 +7;
int a[400];
int main() {
ios::sync_with_stdio(0);
int t,n;
cin>>t;
while(t--)
{
cin>>n;
int x,y;
int d=0;
for(int i=0;i<n;i++)
{
cin>>x>>y;
int ans=max(x,d+1);
if(ans<=y){cout<<ans<<" ";d=ans;}
else{cout<<"0 ";}

}
cout<<endl;




}
 return 0; }