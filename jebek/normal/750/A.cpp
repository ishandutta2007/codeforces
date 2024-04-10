#include<bits/stdc++.h>
using namespace std;


long long n,k,ans;
int main()
{
  cin>>n>>k;
  k=240-k;
  for(int i=1;i<=n;i++)
    if(5*i<=k)
      {
	k-=5*i;
	ans++;
      }
  cout<<ans<<endl;
}