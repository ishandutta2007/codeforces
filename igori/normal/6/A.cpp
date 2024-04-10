#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a, a+4);

    if((a[2]<a[1]+a[0])||(a[3]<a[2]+a[1]))
        {cout<<"TRIANGLE";return 0;}
    if((a[2]==a[1]+a[0])||(a[3]==a[2]+a[1]))
         {cout<<"SEGMENT";return 0;}
                            cout<<"IMPOSSIBLE";






}