#include<iostream>
#include<algorithm>

using namespace std;

long long n,k;

int main()
{
  cin>>n>>k;
  for(int i=1;i<=k;i++)
    cout<<2*i-1<<" "<<2*i<<" ";
  for(int i=k+1;i<=n;i++)
    cout<<2*i<<" "<<2*i-1<<" ";
  cout<<endl;
}