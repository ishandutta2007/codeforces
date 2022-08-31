#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ld PI = 3.1415926535897932384626433832795;
const ld eps = 1e-7;
struct point
{
    ld x,y;
    point(){};
    point(ld _x, ld _y)
    {
        x = _x;
        y = _y;
    }
    point operator + (point& p)
    {
        return point(x+p.x,y+p.y);
    }
    point operator - (point& p)
    {
        return point(x-p.x,y-p.y);
    }
    ld absval()
    {
        return sqrt(x*x+y*y);
    }
};
struct circle{
    ld r;
    point c;
    circle(){};
    circle(ld _r, ld _cx, ld _cy)
    {
        r = _r;c.x = _cx,c.y = _cy;
    }
    ld getarea()
    {
        return PI*r*r;
    }
    ld area_of_intersection(circle c2)
    {
        ld r1 = r,r2=c2.r,d = (c-c2.c).absval();
        if(r1 + r2 < d + eps)
            return 0;
        if(r1 + d < r2 + eps)
            return PI*r1*r1;
        if(r2 + d < r1 + eps)
            return PI*r2*r2;
        ld theta_1 = acos((r1*r1+d*d-r2*r2)/(2*r1*d)),theta_2 = acos((r2*r2+d*d-r1*r1)/(2*r2*d));
        return r1*r1*(theta_1 - sin(2*theta_1)/2.)+r2*r2*(theta_2 - sin(2*theta_2)/2.);
    }
};
int main()
{
    ld x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    cout<< setprecision(10)<<fixed<<circle(r1,x1,y1).area_of_intersection(circle(r2,x2,y2)) <<endl;
}