#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
int n,q,c;
int v[11][105][105];
int main()
{ios::sync_with_stdio(0);
cin>>n>>q>>c;
int x,y,z;
while(n--)
{
cin>>x>>y>>z;
v[z][x][y]++;;


}

for(int t=0;t<=c;t++)
{

for(int i=1;i<=100;i++)
{for(int j=1;j<=100;j++)
{

v[t][i][j]+=v[t][i][j-1]+v[t][i-1][j]-v[t][i-1][j-1];





}

}}
int time,x2,y2,num;


while(q--)
{

cin>>time>>x>>y>>x2>>y2;

int ans=0;
for(int i=0;i<=c;i++)
{
 num=v[i][x2][y2]-v[i][x2][y-1]-v[i][x-1][y2]+v[i][x-1][y-1];
ans+= num * ((i+time)%(c+1));



}
cout<<ans<<endl;


}


return 0;}