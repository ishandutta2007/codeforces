#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  cin>>n;
  cout<<2<<endl;
  for(long long i=2;i<=n;i++)
    cout<<i*i*i+2*i*i+1<<endl;
}