#include <iostream>

using namespace std;
int n, a[100009], b[100009], sa, sb;

int abs(int k)
{
if(k<0)
return -k;
return k;
}
int main()
{
   cin>>n;

for(int i=1;i<=n;i++)
{
cin>>a[i]>>b[i];
sa+=a[i];
sb+=b[i];
}

int high=abs(sa-sb);

int c=0;
for(int i=1;i<=n;i++)
{
    if(high < abs(sa-a[i]+b[i] -(sb-b[i]+a[i]) ))
        high = abs(sa-a[i]+b[i] -(sb-b[i]+a[i]) ), c=i;
}
cout<<c;
}