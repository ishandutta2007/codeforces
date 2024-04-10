// Hydro submission #6259231037de167dd82bd7ac@1650008859186
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d;
    cin>>n;
    a=n/100;
    b=(n-a*100)/20;
    c=(n-a*100-b*20)/10;
    d=(n-a*100-b*20-c*10)/5;
    printf("%d\n",a+b+c+d+n-a*100-b*20-c*10-d*5);
    return 0;
}