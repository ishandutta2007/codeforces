#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
long long a,b,c,g,p,q;
scanf("%I64d%I64d%I64d",&a,&b,&c);
if(1.*b/__gcd(b,c)*c>8e18)
{
p = min(a,min(b,c)-1);
q = a;
}
else
{
g = b/__gcd(b,c)*c;
p = a/g*min(b,c)+min(a%g,min(b,c)-1);
q = a;
}
g = __gcd(p,q);
printf("%I64d/%I64d",p/g,q/g);
}