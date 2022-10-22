#include<bits/stdc++.h>
using namespace std ;
//int a[308];
stack<int> a;
bool speed;
int main()
{
ios::sync_with_stdio(0);

int n,t,u=0,x,l=301,ans=0,sp;
cin>>n;
for(int j=0;j<n;j++)
{cin>>t;
if(t==2){ans+=u;u=0;}
if(t==4)u=0;
if(t==6)u++;
if(t==5){while(!a.empty())a.pop();}
if (t==3){cin>>x;l=x;
a.push(x);
if(l<sp){t=1;speed=true;}
}

if(t==1){
if(!speed){cin>>x;sp=x;}else{x=sp;speed=0;}
while(!a.empty()&&a.top()<x){ans++;a.pop();}


} }

cout<<ans;
return 0;}