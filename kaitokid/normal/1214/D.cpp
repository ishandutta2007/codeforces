#include <bits/stdc++.h>

using namespace std;
long long MOD=2121298673;
vector<long long>a[1000001],b[1000001];
vector<string> ss;
string s;
int n,m;

int main()
{
  ios::sync_with_stdio(0);
cin>>n>>m;
a[0].push_back(1);
for(int i=0;i<n;i++)
{
    cin>>s;
    ss.push_back(s);
    for(int j=0;j<m;j++){b[i].push_back(0);if(ss[i][j]=='#'){a[i].push_back(0);continue;} if(i==0&&j==0)continue; long long r=0;if(j>0)r+=a[i][j-1];
    if(i>0)r+=a[i-1][j]; a[i].push_back(r%MOD);}
}
if(a[n-1][m-1]<2){cout<<a[n-1][m-1];return 0;}
b[n-1][m-1]=1;
for(int i=n-1;i>=0;i--)
    for(int j=m-1;j>=0;j--)
{
    if(i==0&&j==0)break;
        if(i==n-1&&j==m-1)continue;
    if(ss[i][j]=='#')continue;
    if(j<m-1)b[i][j]+=b[i][j+1];
    if(i<n-1)b[i][j]+=b[i+1][j];
b[i][j]%=MOD;
    if((b[i][j]*a[i][j])%MOD==a[n-1][m-1]){cout<<1;return 0;}
}
cout<<2;
    return 0;
}