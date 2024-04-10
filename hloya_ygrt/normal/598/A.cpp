#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;
/*int last(int n)
{
    int t=0;
    while (n%2==0)
    {
        t++;


}*/
int main()
{
    ll n,a;
    scanf("%I64d",&n);

    for (ll i=0;i<n;i++)
    {
        scanf("%I64d",&a);

        long double t=(long double) a;
        ll last=(ll)floor(log2(t));

        int z=pow(2,last);
        z*=2; z--;

        long double x=(long double)a/2.0,y=a+1.0;
        ll ans=(ll)(y*x);
        printf("%I64d\n",ans-2*z);
    }


    return 0;
}