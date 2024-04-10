// Hydro submission #631f326dbdf9bc31d15c8881@1662988910780
#include<bits/stdc++.h>
#define v(l,n) n*sqrt(1-1/(sin(PI/n)*sin(PI/n)*4))/(tan(PI/n)*12)*l*l*l
using namespace std;
const double PI=acos(-1);
int main()
{
    int l3,l4,l5;
    cin>>l3>>l4>>l5;
    printf("%.12lf\n",v(l3,3)+v(l4,4)+v(l5,5));
    return 0;
}