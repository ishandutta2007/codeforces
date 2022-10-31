// Hydro submission #62677bf19f31360077e12bc9@1650949106927
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[11],i;
    for(i=0;i<11;i++)
    cin>>a[i];
    for(i=10;i+1;i--)
    {
        double r=5*pow(a[i],3)+sqrt(abs(a[i]));
        if(r>400) printf("f(%d) = MAGNA NIMIS!\n",a[i]);
        else printf("f(%d) = %.2f\n",a[i],r);
    }
    return 0;
}