#include <iostream>
#include <cmath>
#define EPS 0.0000001
using namespace std;

double x, y, a, b, r;

int abs(int k)
{
    if(k<0)
        return -k;
    return k;
}

bool check(double p, double d)
{
    if(d<p*2*r+EPS)
        return true;
    return false;
}

int main()
{
cin>>r>>x>>y>>a>>b;


    double d=sqrt((a-x)*(a-x)+(b-y)*(b-y));
    int ans=d/(2*r);

    for(double g=ans-5;g<=ans+5;g++)
        if(check(g, d))
        {
        cout<<g;
        return 0;
        }



    return 0;
}