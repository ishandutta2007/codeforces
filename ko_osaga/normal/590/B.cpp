#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int x1, x2, yy1, y2, v, t;
int vx, vy, wx, wy;

bool trial(double x){
    double dx = x2 - x1 - vx * min(x, 1.0 * t) - wx * max(x - t, 0.0);
    double dy = y2 - yy1 - vy * min(x, 1.0 * t) - wy * max(x - t, 0.0);
    return hypot(dx, dy) <= v * x;
}

int main(){
    scanf("%d %d %d %d %d %d",&x1,&yy1,&x2,&y2,&v,&t);
    scanf("%d %d %d %d",&vx,&vy,&wx,&wy);
    double s = 0, e = t;
    for(int i=0; i<100; i++){
        double m = (s+e)/2;
        if(trial(m)) e = m;
        else s = m;
    }
    if(trial(t)) printf("%.12f",s);
    else{
    double s = t, e = 1e9;
    for(int i=0; i<100; i++){
        double m = (s+e)/2;
        if(trial(m)) e = m;
        else s = m;
    }
printf("%.12f",s);
    }
}