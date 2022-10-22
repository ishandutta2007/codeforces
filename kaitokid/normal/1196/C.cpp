#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int q,n,x,y;
int f1,f2,f3,f4;
int mxx,mnx,mxy,mny;
int main()
 {ios::sync_with_stdio(0); 
cin>>q;
while(q--)
{
mxx=100000,mnx=-100000,mxy=100000,mny=-100000;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x>>y>>f1>>f2>>f3>>f4;
if(f1==0)mnx=max(mnx,x);
if(f2==0)mxy=min(mxy,y);
if(f3==0)mxx=min(mxx,x);
if(f4==0)mny=max(mny,y);


}
if(mny>mxy||mnx>mxx){cout<<0<<endl;continue;}
cout<<1<<" "<<mnx<<" "<<mny<<endl;


}
 return 0; }