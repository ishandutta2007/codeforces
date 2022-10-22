#include <bits/stdc++.h>
using namespace std;
//int a[6][8];
map<int,int>mp;
int a[29],b[29];
int num;
int x,y;
int main()
{ios::sync_with_stdio(0);
int n;
cin>>n;

for(int i=0;i<n;i++)
{cin>>a[i];b[i]=a[i];}
sort(b,b+n);
for(int i=0;i<n-1;i++)
mp[b[i]]=b[i+1];
mp[b[n-1]]=b[0];
for(int i=0;i<n;i++)
cout<<mp[a[i]]<<" ";
return 0;}