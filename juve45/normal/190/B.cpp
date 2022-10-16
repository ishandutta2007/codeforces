#include <bits/stdc++.h>

using namespace std;
int x, y, r;
int X, Y, R;

int main()
{
cin>>x>>y>>r;
cin>>X>>Y>>R;
    int a=X-x;
    a*=a;
    int b=Y-y;
    b*=b;
    double d=sqrt(a+b);

    if(d > r+R)
    {
        printf("%.7f", (d-R-r)/2.);
        return 0;
    }
    if((d<R || d<r) && d+r>R && d+R>r)
    {
        printf("%.7f", 0.);
    }
    else{

        double res=max(R, r)-d-min(R, r);
        if(res>0)
        printf("%.7f", res/2.);
        else printf("%.7f", 0.);
    }

    return 0;
}