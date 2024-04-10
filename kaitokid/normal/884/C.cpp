#include <bits/stdc++.h>
using namespace std ; 
long long a[100009];

bool vis[100009];
vector<long long>vc;
long long ws(long long x)
{
return x*x;


}
int main() 
{

int n;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>a[i];



}
for(int i=0;i<n;i++)
{
int v=0;
int d=i;
if(vis[i])continue;
while(!vis[d])
{
v++;
vis[d]=true;
d=a[d]-1;
//cout<<d<<endl;

}
vc.push_back(v);
}
sort(vc.begin(),vc.end());
//cout<<vc[0]<<" "<<vc[1]<<" "<<vc[2];
if(vc.size()<2){cout<<vc[0]*vc[0];return 0;}
long long  q=vc.size()-1;
long long ans=ws(vc[q]+vc[q-1]);
for(long long  i=0;i<q-1;i++)
ans+=ws(vc[i]);
cout<<ans;
return 0;
}