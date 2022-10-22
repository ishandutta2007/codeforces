#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
int n,m,a[200009],num[5000009],wh[200009];
void go(int fir,int en,int i,int u)
{
if(fir==en){num[i]=a[fir];wh[fir]=i;return;}
int mid=(fir+en)/2;
go(fir,mid,2*i,(u+1)%2);
go(mid+1,en,2*i+1,(u+1)%2);
if(u==0)num[i]=num[2*i]^num[2*i+1];
else num[i]=num[2*i]|num[2*i+1];




}
int main() 
{ 
ios::sync_with_stdio(0);
cin>>n>>m;
int q=n;
n=1;
for(int i=0;i<q;i++)n*=2;
for(int i=0;i<n;i++)cin>>a[i];
go(0,n-1,1,q%2);

int x,y;
while(m--)
{
cin>>x>>y;
x--;
num[wh[x]]=y;
int r=wh[x],u=1;
r/=2;
while(r>0)
{
if(u==1)num[r]=num[2*r]|num[2*r+1];else num[r]=num[2*r]^num[2*r+1];
r/=2;
u=(u+1)%2;
}
cout<<num[1]<<endl;

}




return 0 ;}