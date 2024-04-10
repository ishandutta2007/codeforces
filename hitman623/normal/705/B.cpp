
#include <iostream>

using namespace std;

int main()
{
   long n,a[100000],i,s=0;
   cin>>n;
   for(i=0;i<n;++i)
   {cin>>a[i];a[i]-=1;}
   for(i=0;i<n;++i)
   {s+=a[i];
   if(s%2==0) cout<<"2"<<endl;
   else cout<<"1"<<endl;}
    return 0;
}