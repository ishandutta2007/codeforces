#include<bits/stdc++.h>
double a,v,l,d,w;
double dist(const double &speed,const double &time) {
    return (speed*time+a*time*time*0.5);
}
double traveltime(const double &distan,const double &speed) {
    double delta=speed*speed+2.0*a*distan;
    double tall=(sqrt(delta)-speed)/a;
    double tmax=(v-speed)/a;
    if (tmax>=tall) return (tall);
    double dmax=dist(speed,tmax);
    return (tmax+(distan-dmax)/v);
}
void process(void) {
    scanf("%lf",&a);
    scanf("%lf",&v);
    scanf("%lf",&l);
    scanf("%lf",&d);
    scanf("%lf",&w);
    if (v<=w) {
        printf("%.9lf",traveltime(l,0));
        return;
    }
    double tw=w/a;
    double dw=dist(0.0,tw);
    if (dw>=d) {
        printf("%.9lf",traveltime(l,0));
        return;
    }
    printf("%.9lf",tw+2.0*(traveltime(0.5*(d-dw),w))+traveltime(l-d,w));
}
int main(void) {
    process();
    return 0;
}