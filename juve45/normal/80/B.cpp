#include <iostream>
#include <cstdio>
using namespace std;

double a, b;
char c;

double minutes[62];
double h[24];

int main()
{
    cin>>a;
    cin>>c;
    cin>>b;
    double minutes;
    if(a>=12)a-=12;
    minutes=b*6;
    double hours=(a+b/60)*30;
    printf("%.9f %.9f", hours, minutes);

    return 0;
}