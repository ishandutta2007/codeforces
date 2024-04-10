// Hydro submission #631f322032ae6c3198c914a7@1662988832893
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    double m=sqrt(b*b-4*a*c),x1=(b-m)/a/-2,x2=(b+m)/a/-2;
    if(a<0) swap(x1,x2);
    printf("%.15lf\n%.15lf\n",x1,x2);
    return 0; 
}