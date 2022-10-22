#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
int n;
ll num,k,ans=1000000000000000000;
ll a[100009];
vector<int>v[100009];
bool bl;
void dfs(int i,int pr,ll r)
{
if(bl)return ;

if(v[i].size()==1)
{if(k==0)k=r;else{
ll g=__gcd(r,k);
ll f =(k/g)*r;
ll u=((k%g)*r)/g;
k =f+u;
if(k>num){cout<<num;bl=true;return ;}

}
ans=min(ans,r*a[i]);


return ;
}

for(int j=0;j<v[i].size();j++)
{
if(v[i][j]==pr)continue;
dfs(v[i][j],i,r*(v[i].size()-1));


}





}
int main()
{
cin>>n;

for(int i=1;i<=n;i++)
{
cin>>a[i];

num+=a[i];

}
int x,y;
for(int i=0;i<n-1;i++)
{

cin>>x>>y;
v[x].push_back(y);
v[y].push_back(x);


}
v[1].push_back(0);
dfs(1,0,1);
if(bl)return 0;
ans=min(ans,num);
ans-=(ans%k);
cout<<num-ans;

return 0;}