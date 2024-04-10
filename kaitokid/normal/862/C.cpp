#include <iostream>

using namespace std;

int main()
{
  int n,x;
  cin>>n>>x;
  if(n==2&&x==0){cout<<"NO";return 0;}
  cout<<"YES"<<endl;
  if(n==1){cout<<x;return 0;}
  if(n==2){cout<<1<<" "<<(1^x);return 0;}
  for(int i=1;i<n-2;i++){cout<<i<<" ";x^=i;}
  if((x^(n-2))==0){cout<<n-1<<" ";x^=(n-1);}else {cout<<n-2<<" ";x^=(n-2);}
  for(int i=n;i<1e6+1;i++)
  {
      if((x^i)>n){cout<<i<<" "<<(x^i);return 0;}
  }
    return 0;
}