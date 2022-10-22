#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n , s[300009],ans=0,k;
vector<int>a[300009];
int fuck(int x)
{
if(a[x].size()==0){k++;return 1;}
if(s[x]==0)
{
int d=0;
for(int i=0;i<a[x].size();i++)
{int r=fuck(a[x][i]);d+=r;}
return d;


}
int d=9999999;
for(int i=0;i<a[x].size();i++)
{int r=fuck(a[x][i]); d=min(d,r);}
return d;
}
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)cin>>s[i];
int x;
for(int i=2;i<=n;i++){cin>>x;
a[x].push_back(i);}
int y=fuck(1);
cout<<k-y+1;
return 0;
}