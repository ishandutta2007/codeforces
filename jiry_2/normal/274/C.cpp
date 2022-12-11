#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define sqr(x) ((x)*(x))
struct point{
    double x,y;
}x[110];
struct point2{
    int x,y;
    void scan(){
        scanf("%d%d",&x,&y);
    }
}y[110];
int n;
struct line{
    double a,b,c;
};
line getli(point k1,point k2){
    double k3=k1.x-k2.x,k4=k1.y-k2.y; 
    point a=(point){(k1.x+k2.x)/2.0,(k1.y+k2.y)/2.0}; 
    double k5=a.x*k3+a.y*k4;
//  cout<<k1.x<<" "<<k1.y<<" "<<k2.x<<" "<<k2.y<<" "<<k3<<" "<<k4<<" "<<k5<<endl; 
    return (line){k3,k4,k5};
}
double dis(point k1,point k2){
    return sqr(k1.x-k2.x)+sqr(k1.y-k2.y);
}
point cross(line k1,line k2){
    return (point){(k1.c*k2.b-k1.b*k2.c)/(k1.a*k2.b-k1.b*k2.a),(k1.c*k2.a-k1.a*k2.c)/(k1.b*k2.a-k1.a*k2.b)};
}
int check(point k1,double k2){
    for (int i=1;i<=n;i++) if (dis(x[i],k1)+1e-8<k2) return 0; return 1;
}
int main(){
    scanf("%d",&n); for (int i=1;i<=n;i++) {y[i].scan(); x[i]=(point){y[i].x,y[i].y};} double ans=-1;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (y[i].x==y[j].x)
                for (int k=1;k<=n;k++)
                    if (i!=k&&y[i].y==y[k].y)
                        for (int k1=1;k1<=n;k1++)
                            if (k1!=j&&y[k1].y==y[j].y){
                                point k2=(point){(x[i].x+x[k].x)/2.0,(x[i].y+x[j].y)/2.0};
                                double k3=dis(k2,x[i]); if (check(k2,k3)) ans=max(ans,k3);
                            }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=j+1;k<=n;k++){
                double k1=dis(x[i],x[j]),k2=dis(x[j],x[k]),k3=dis(x[k],x[i]); //cout<<k1<<" "<<k2<<" "<<k3<<endl;
                if (2*max(k1,max(k2,k3))<k1+k2+k3-1e-8){
                    point k4=cross(getli(x[i],x[j]),getli(x[j],x[k])); double k5=dis(k4,x[i]); //cout<<"asdasd "<<i<<" "<<j<<" "<<k<<" "<<k4.x<<" "<<k4.y<<endl;
                    if (check(k4,k5)) ans=max(ans,k5);
                }
            }
    if (ans<0) cout<<-1<<endl; else printf("%.11lf\n",sqrt(ans)); return 0;
}