#include <bits/stdc++.h>
using namespace std;
bool a[1000000];
int main()
{
ios::sync_with_stdio(0);
for(int i=0;i<100;i++)
{

for(int j=0;j<100;j++)
a[7*i+3*j]=true;


}
int n ;
cin>>n;
int x;
for(int i=0;i<n;i++)
{

cin>>x;
if(a[x]){cout<<"YES"<<endl;continue;}
cout<<"NO"<<endl;


}
return 0;}