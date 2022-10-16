#include <iostream>
#include <cstdio>
#define PI 3.14159265359

using namespace std;

double d, h, v, e, l;

bool isOK(double sec)
{
    if(h-l*sec+e*sec<0) return true;
    return false;
}

double caut_bin(double st, double dr)
{
    if(dr-st<0.00001)
        return st;
    double mid=st+dr;
    mid/=2;
    if(isOK(mid)) return caut_bin(st, mid);
    else return caut_bin(mid, dr);
}

int main()
{
cin>>d>>h>>v>>e;

l=4.*v/(PI*d*d);

if(isOK(10001))
    {
        cout<<"YES\n";
        printf("%.5f", caut_bin(0., 10000.));
    }
else
    cout<<"NO\n";
    return 0;
}