#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int MOD=1e9 +7;
int n,ans;
bool a[102][102];
int main() {
ios::sync_with_stdio(0);
cin>>n;
ans=n-1;
for(int i=2;i<=n;i++)
{
a[i-1][i]++;

for(int j=i%2+1;j<i-2;j+=2)
{ans++;
a[j][i]++;

}
}
cout<<ans<<endl;
for(int i=1;i<n;i++)
{
for(int j=i+1;j<=n;j++)
{
if(a[i][j])cout<<i<<" "<<j<<endl;

}


}
 return 0; }