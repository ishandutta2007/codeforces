#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld pi=acos(-1.L);
ld x,y,xx,yy,vx,vm,t,vy,wx,wy;
bool poss(ld t0){
    ld x0,y0;
    if(t0<t){
        x0=x-vx*t0;
        y0=y-vy*t0;
    }
    else{
        x0=x-vx*t-wx*(t0-t);
        y0=y-vy*t-wy*(t0-t);
    }
    return t0*vm>=sqrt(x0*x0+y0*y0);
}
int main()
{
    cin>>x>>y>>xx>>yy>>vm>>t>>vx>>vy>>wx>>wy;
    x=xx-x,y=yy-y;
    ld cur=0;
    for(ld i=1e20;i>1e-20;i/=2){
        if(!poss(cur+i))cur+=i;
    }
    printf("%.20Lf",cur);
}