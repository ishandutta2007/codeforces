#include <bits/stdc++.h>

using namespace std;

double t, v;
double x1, x2, y1, y2, v1x, v2x, v1y, v2y;

bool canReach(double time)
{
    double X, Y;
    double dist=v*time;
    if(time>t)
    {
        time-=t;
        X=x1+v1x*t;
        Y=y1+v1y*t;
    X+=v2x*time;
    Y+=v2y*time;
    }
    else X=x1+v1x*time, 
         Y=y1+v1y*time;
    double x=x2-X;
    double y=y2-Y;
    if(dist*dist < x*x+y*y)
        return false;
    return true;
    
}

double caut(double start, double finish)
{
    if(finish-start<=0.00000005)
        return finish;
    double mid=(start+finish)/2;
    if(canReach(mid)) return caut(start, mid);
    else return caut(mid, finish);
}

int main()
{
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>v>>t;
    cin>>v1x>>v1y;
    cin>>v2x>>v2y;
    double ans;
    if(canReach(t))
    ans=caut(0, t);
    else ans=caut(t, 2000000000.);
    
    printf("%.9f\n", ans);



    return 0;
}