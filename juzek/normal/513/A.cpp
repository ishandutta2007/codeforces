#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;


int main()
{
    float a,b,c,d;
    scanf("%f %f %f %f",&a,&b,&c,&d);
    if (a == b)
        printf("Second");
    else if (a > b)
        printf("First");
    else
        printf("Second");
    return 0;
}