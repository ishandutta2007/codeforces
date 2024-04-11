#include<iostream>
#include <iomanip>
#include<cmath>
const double pi =     2.0*acos(0.0);
using namespace std;
int main()
{
    double n,r;
    cin>>n>>r;
    double R,y;
    y=sin(pi/n);
    R=((r*y)/(1-y));
    cout << std::fixed<<setprecision(7) << R <<endl;
}