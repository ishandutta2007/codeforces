#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
    double p;
    int t1,t2,w1,w2;
    void scan(){
        scanf("%d%d%d%d%lf",&w1,&w2,&t1,&t2,&p);
    }
}x[2000];
int n,t;
long double score[1100][1600],time[1100][1600],limnum=1e-9;
int compare(point w1,point w2){
    return w1.t2*w1.p/(1-w1.p)<w2.t2*w2.p/(1-w2.p);
}
void update(int w1,int w2,long double w3,long double w4){
    if (w2>t) return;
    if (score[w1][w2]+limnum<w3){
        score[w1][w2]=w3; time[w1][w2]=w4;
    } else if (fabs(score[w1][w2]-w3)<limnum) time[w1][w2]=min(time[w1][w2],w4);
}
int main(){
    scanf("%d%d",&n,&t); for (int i=1;i<=n;i++) x[i].scan(); sort(x+1,x+n+1,compare);
    for (int i=1;i<=n;i++)
        for (int j=0;j<=t;j++){
            update(i+1,j,score[i][j],time[i][j]);
            update(i+1,j+x[i].t1,score[i][j]+x[i].w1,time[i][j]+x[i].t1);
            update(i+1,j+x[i].t1+x[i].t2,score[i][j]+x[i].w1+x[i].w2*(1-x[i].p),time[i][j]*x[i].p+x[i].t1+(x[i].t2+j)*(1-x[i].p));
        }
    long double num=time[n+1][t];
    for (int i=0;i<t;i++) if (fabs(score[n+1][i]-score[n+1][t])<limnum) num=min(num,time[n+1][i]);  
    printf("%.11lf %.11lf\n",(double)score[n+1][t],(double)num); return 0;
}