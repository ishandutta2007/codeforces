#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum,n;
int x,r=-1;
map<int,int> mp;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++){cin>>x;sum+=x;if(mp[x]==2){cout<<"cslnb";return 0;}
mp[x]++;
if(mp[x]==2)
{if(r!=-1){cout<<"cslnb";return 0;}
r=x;
}
}
if(mp[0]==2){cout<<"cslnb";return 0;}
if((r!=-1) && mp[r-1]>0){cout<<"cslnb";return 0;}
sum-=(n*(n-1))/2;
if(sum%2==0)cout<<"cslnb";else cout<<"sjfnb";
return 0;
}