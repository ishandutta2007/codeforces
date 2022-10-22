#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int MOD=1e9 +7;
char x;
bool bl[2009][2009];
int n,m,k;
int main() {
ios::sync_with_stdio(0);
cin>>n>>m>>k;
for(int i=0;i<n;i++)
{for(int j=0;j<m;j++)
{
cin>>x;
if(x=='*')bl[i][j]++;
}
}
int ans=0;
for(int i=0;i<n;i++)
{
int d=0;
for(int j=0;j<m;j++)
{
d++;
if(bl[i][j])d=0;
if(d>=k)ans++;



}
}
for(int j=0;j<m;j++)
{int d=0;
for(int i=0;i<n;i++)
{
d++;
if(bl[i][j])d=0;
if(d>=k)ans++;
}
}
if(k==1)ans/=2;
cout<<ans;
 return 0; }