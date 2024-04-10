#include <bits/stdc++.h> 
using namespace std ;
vector<int>a;
int n;
bool d(int v)
{int an=v;

while(v!=0)
{an+=v%10;
v/=10;}
if(an==n)return true;

return false;}

 int main(){
ios::sync_with_stdio(0);
cin>>n;
for(int i=max(n-100,0);i<=n;i++)
{if(d(i))a.push_back(i);}
cout<<a.size()<<endl;
for(int i=0;i<a.size();i++)cout<<a[i]<<endl;
return 0;}