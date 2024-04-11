//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int test()
{
    int a, b, c, d;
    int ar = -1000007, geo = -1000007; 
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int r = b-a;
    if(c-b==r && d-c==r)
        ar = d+r;
    double q = 1.0*b/a;
    //printf("%lf\n", q);
    if(1.0*c/b==q && 1.0*d/c==q)
    {
        double e = 1.0*d*q;
        if(e==int(e))
            geo = e;
    }
    if(ar==-1000007 && geo == -1000007)
        return 42;
    if(ar != geo && ar!=-1000007 && geo != -1000007)
        return 42;
    if(ar != -1000007)
        return ar;
    return geo;
}

int main()
{
    int t = 1;
    while(t--)
        printf("%d\n", test());
    return 0;
}