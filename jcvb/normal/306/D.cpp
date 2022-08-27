#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db pi=acos(-1);
struct line{db d,t;}l[105];
struct point{db x,y;};
db det(db a,db b,db c,db d){return a*d-b*c;}
point inter(line a,line b){
    point ret;
    ret.x=det(a.d,-cos(a.t),b.d,-cos(b.t))/det(sin(a.t),-cos(a.t),sin(b.t),-cos(b.t));
    ret.y=det(sin(a.t),a.d,sin(b.t),b.d)/det(sin(a.t),-cos(a.t),sin(b.t),-cos(b.t));
    return ret;
}
db dist(point a,line b){
    return fabs(a.x*sin(b.t)-a.y*cos(b.t)-b.d);
}
int n;
int main()
{
    scanf("%d",&n);
    if(n<=4){
        printf("No solution\n");
        return 0;
    }
    db w=2*pi/n;
    for (int i=0;i<n;i++)l[i]=(line){26.0*n,w*i};
    for (int i=1;i<n;i++){
        db di=dist(inter(l[i-1],l[(i+1)%n]),l[i]);
        l[i].d+=(i*1.0/n)*di;
    }
    for (int i=0;i<n;i++){
        point t=inter(l[i],l[(i+1)%n]);
        printf("%.6lf %.6lf\n",t.x,t.y);
    }
    return 0;
}