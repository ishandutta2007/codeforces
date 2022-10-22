#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
int n,m;
int similar=0;
bool bl=true;
int a[100009];
int b[100009];
int main()
{ios::sync_with_stdio(0);
cin>>n>>m;
cin>>a[1];
for(int i=2;i<=n;i++)
{
cin>>a[i];
if(a[i]<a[i-1])bl=true;
//cout<<bl<<" "<<similar<<endl;
if(a[i]>a[i-1]&&bl){b[i]=i-1-similar;bl=false;similar=0;continue;}
b[i]=b[i-1];
if(a[i]==a[i-1])similar++;
else similar=0;

}
int x,y;
for(int i=0;i<m;i++)
{
cin>>x>>y;
if(b[y]<=x)cout<<"Yes\n";
else cout<<"No\n";



}
return 0;}