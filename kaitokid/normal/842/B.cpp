#include<bits/stdc++.h>
using namespace std;
int ans;
int main()
{
int r,d,n,x,y,l;
cin>>r>>d>>n;
d=r-d;
for(int i=0;i<n;i++)
{cin>>x>>y>>l;
double v=sqrt(x*x+y*y+0.0);
if(v<d+l||v+l>r)continue;
/*v=sqrt((x+l+0.0)*(x+l)+(y)*(y)+0.0);
if(v>r)continue;
v=sqrt((x-l+0.0)*(x-l)+(y)*(y)+0.0);
if(v>r)continue;
v=sqrt((x+0.0)*(x)+(y-l)*(y-l)+0.0);
if(v>r)continue;
v=sqrt((x+0.0)*(x)+(y+l)*(y+l)+0.0);
if(v>r)continue;*/
ans++;
}
cout<<ans;

return 0;
}