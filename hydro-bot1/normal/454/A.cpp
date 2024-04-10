// Hydro submission #6255047217cd4d0a417644ad@1649738866991
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a,b;
    cin>>n;
    a=n/2;b=n-1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<abs(a);j++)
        printf("*");
        for(j=0;j<n-abs(b);j++)
        printf("D");
        for(j=0;j<abs(a);j++)
        printf("*");
        cout<<endl;
        a--,b-=2;
    }
    return 0;
}