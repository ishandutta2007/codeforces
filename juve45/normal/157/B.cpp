#include <bits/stdc++.h>
#define PI 3.141592653589793238462

using namespace std;
double ans;
int a[123], n;
double area(int a, int b)
{
    return PI*b*b-PI*a*a;
}


int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
a[0]=0;
sort(a+1, a+n+1);
int i;
if(n%2==0)
i=1;
else i=0;

while(i<n)
{
    ans+=area(a[i], a[i+1]);
    i+=2;
}

printf("%.7f", ans);
    return 0;
}