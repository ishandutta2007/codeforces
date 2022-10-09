#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#define PI 3.14159265358979323
using namespace std;

double yy1,yy2,yw,xb,yb,rad;

void ucitaj(){
    scanf("%lf%lf%lf%lf%lf%lf",&yy1,&yy2,&yw,&xb,&yb,&rad);
}

void resi(){
    double ytgt,disrfc,h;
    yw-=rad;
    yy2=2*yw-yy2;
    yy1=2*yw-yy1;
    ytgt = yy1-rad;
    disrfc = (ytgt-yy2)*xb;
    h = disrfc / sqrt((ytgt-yb)*(ytgt-yb) + xb*xb);
    //printf("%.3lf\n",ytgt);
    if (h > rad){
        printf("%.14lf\n",xb*(ytgt-yw)/(ytgt-yb));
    } else {
        printf("-1\n");
    }
}

int main(){
    ucitaj();
    resi();
    return 0;
}