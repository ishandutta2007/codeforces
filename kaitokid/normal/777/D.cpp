#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<string>a;
string s;
int lon[500009];
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
{cin>>s;a.push_back(s);}
lon[n-1]=a[n-1].size();
for(int i=n-2;i>=0;i--)
{
for(int j=1;j<min(int(a[i].size()),lon[i+1]);j++)
{
if(a[i][j]<a[i+1][j]){lon[i]=a[i].size();break;}
if(a[i][j]>a[i+1][j]){lon[i]=j;break;}

}
if(lon[i]==0)lon[i]=min(int(a[i].size()),lon[i+1]);


}
for(int i=0;i<n;i++)
{for(int j=0;j<lon[i];j++)cout<<a[i][j];
cout<<endl;}
return 0;}