#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000090];
int d[2000009][11];
int main()
{

ios::sync_with_stdio(0);
 for(int i=1;i<10;i++)a[i]=i;
for(int i=1;i<2000009;i++)
{
int l=1;
int g=i;
while(g!=0)
{
if(g%10!=0)l*=(g%10);
g/=10;


}
for(int j=1;j<10;j++)d[i][j]=d[i-1][j];
a[i]=a[l];
//if(a[l]==4&&i<70)cout<<i;
d[i][a[l]]++;


}
int q;
cin>>q;
while(q--)
{
int x,y,z;
cin>>x>>y>>z;
//cout<<d[y][z]<<" "<<d[x][z];
cout<<d[y][z]-d[x-1][z]<<endl;


}




return 0;}