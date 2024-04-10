#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll ans;
int main() {
ios::sync_with_stdio(0);
int n;
cin>>n;
for(int i=1;i<=n;i++)
{

for(int j=i;j<=n;j++)
{
int x=i^j;
if(x>=j&&i+j>x&&x-j<i&&i+x>j&&j+x>i&&x-i<j&&j-i<x&&x<=n)ans++;
}

}
cout<<ans;
 return 0 ;}