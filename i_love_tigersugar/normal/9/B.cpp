#include<cstdio>
#include<cmath>
#define MAX   100000
struct point {
    int x,y;
    point(){}
    point(const int &_x,const int &_y) {
        x=_x;y=_y;
    }
};
double dis(const point &a,const point &b) {
    return hypot(a.x-b.x,a.y-b.y);
}
point a[MAX];
int n;
int vs,vb;
point u;
void init(void) {
    double res=1e14;
    int ib;
    int i,x;
    scanf("%d",&n);
    scanf("%d",&vb);
    scanf("%d",&vs);
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&x);
        a[i]=point(x,0);
    }
    scanf("%d",&u.x);
    scanf("%d",&u.y);
    for (i=2;i<=n;i=i+1) {
        if (dis(point(0,0),a[i])/vb+dis(a[i],u)/vs<=res) {
            res=dis(point(0,0),a[i])/vb+dis(a[i],u)/vs;
            ib=i;
        }
    }
    printf("%d",ib);
}
int main(void) {
    init();
    return 0;
}