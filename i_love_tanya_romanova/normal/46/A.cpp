
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
long n,p;
int main()
{
cin>>n;p=1;
for (int i=1;i<n;i++)
{
p+=i;while (p>n)p-=n;cout<<p;if (i<n)cout<<" ";else cout<<endl;
}
return 0;
}