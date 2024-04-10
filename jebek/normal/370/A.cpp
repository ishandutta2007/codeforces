#include<iostream>
#include<algorithm>

using namespace std;

long long a1,a2,b1,b2;

int main()
{
  cin>>a1>>b1>>a2>>b2;
  if(a1==a2 || b1==b2)
    cout<<1<<" ";
  else
    cout<<2<<" ";
  if((a1+b1)%2!=(a2+b2)%2)
    cout<<0<<" ";
  else if(a1+b1==a2+b2 || a1-b1==a2-b2)
    cout<<1<<" ";
  else
    cout<<2<<" ";
  cout<<max(max(a1-a2,a2-a1),max(b1-b2,b2-b1))<<endl;
}