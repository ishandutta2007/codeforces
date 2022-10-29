#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  long long int n,i=1,a=2;
  cin>>n;
  while(i!=n+1)
  {   cout<<i*(i+1)*(i+1)-a/i<<endl;
     a=i*(i+1);
     ++i;
  }
    return 0;
}