#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
double pi=acos(-1);
struct point{
    double x,y;
}y[200];
struct line{
    double a,b,c;
};
struct atom{
    double d,t;
}x[200];
int n;
line getline(atom k1){
    point k2=(point){-cos(k1.t)*k1.d,sin(k1.t)*k1.d};
    line k3; k3.a=cos(k1.t); k3.b=-sin(k1.t); k3.c=k3.a*k2.x+k3.b*k2.y;
    return k3;
}
point pointer(line k1,line k2){ 
    return (point){(k1.c*k2.b-k2.c*k1.b)/(k1.a*k2.b-k2.a*k1.b),(k1.c*k2.a-k2.c*k1.a)/(k1.b*k2.a-k2.b*k1.a)};
}
#define sqr(x) ((x)*(x))
double dis(line k1,point k2){
    return fabs(k2.x*k1.a+k2.y*k1.b-k1.c)/sqrt(sqr(k1.a)+sqr(k1.b));
}
double geta(point k1,point k2,point k3){
    return acos(((k2.x-k1.x)*(k2.x-k3.x)+(k2.y-k1.y)*(k2.y-k3.y))/(sqrt(sqr(k2.x-k1.x)+sqr(k2.y-k1.y))*sqrt(sqr(k2.x-k3.x)+sqr(k2.y-k3.y))));
}
int main(){
    scanf("%d",&n); if (n<=4){cout<<"No solution"<<endl; return 0;}
    for (int i=1;i<=n;i++) x[i]=(atom){26*n,pi*2/n*(i-1)};
    for (int i=2;i<=n;i++){
        point k1=pointer(getline(x[i-1]),getline(x[i%n+1]));
        double d=dis(getline(x[i]),k1); 
//      cout<<k1.x<<" "<<k1.y<<" "<d<<endl;
        x[i].d+=d*(i-1)*1.0/n/2;
    }
//  cout<<endl;
    for (int i=n;i;i--){
        point k1=pointer(getline(x[i]),getline(x[i%n+1]));
        printf("%.11lf %.11lf\n",k1.x,k1.y);
    }
//  for (int i=1;i<=n;i++)
//      y[i]=pointer(getline(x[i]),getline(x[i%n+1]));
//  for (int i=1;i<=n;i++) printf("%.11lf %.11lf %.11lf\n",geta(y[(i+n-2)%n+1],y[i],y[i%n+1]),y[i].x,y[i].y);
    return 0;
}