// Hydro submission #631f3257bdf9bc31d15c8843@1662988893340
#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
int main()
{
    int n,r;
    cin>>n>>r;
    printf("%.12lf\n",sin(PI/n)*sin(PI/(2*n))/sin(PI-PI*3/2/n)*n*r*r);
    return 0;
}