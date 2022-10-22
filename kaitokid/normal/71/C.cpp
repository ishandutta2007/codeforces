#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
bool bl;
int main(){
int n,x;
cin>>n;
int u=n;
int p=3;

while(u>2)
{if(u%p==0){a.push_back(p);
while(u%p==0){u/=p;}}
p++;}

for(int i=0;i<n;i++)
{cin>>x;
b.push_back(x);}
for(int i=0;i<a.size();i++)
{int l =n/a[i];
for(int j=0;j<l;j++)
{for(int v=j;v<n;v+=l)
{ if(b[v]==0){bl=true;break;} }
if(!bl){cout<<"YES";return 0;}
bl=false;}}
cout<<"NO";
return 0;
}