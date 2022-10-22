#include <bits/stdc++.h>
using namespace std;
bool a[200];
int main(){
ios::sync_with_stdio(0);
int n,x,y;

cin>>n>>x;
int ans=x;
for(int i=0;i<n;i++)
{cin>>y;
if(y<x)ans--;
if(y==x)ans++;}
cout<<ans;



return 0;}