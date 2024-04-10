#include <cstdio>
#include <algorithm>
using namespace std;

void eksdet(double a,double b,double c,double d,double e,double &lo,double &hi){
    lo = 1e50;
    hi = -1e50;
    for (int A=-1; A<=1; A+=2)
    for (int B=-1; B<=1; B+=2)
    for (int C=-1; C<=1; C+=2)
    for (int D=-1; D<=1; D+=2){
        double det = (a+A*e)*(d+D*e) - (b+B*e)*(c+C*e);
        if (det < lo) lo = det;
        if (det > hi) hi = det;
    }
}

int main(){
    double a,b,c,d,l,r,m,lo,hi;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    l=0;
    r=1e15;
    while ((r-l)/(r+l) > 1e-11){
        m = (l+r)/2;
        eksdet(a,b,c,d,m,lo,hi);
        if (lo<0 && hi>0){
            r = m;
        } else {
            l = m;
        }
    }
    printf("%.11lf\n",l);
    return 0;
}