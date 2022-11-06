//Problem I
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,tot,seq[N],qwq,ans;
double d1,d2,ax[N],ay[N],bx[N],by[N],dist[N],dab[N];
double sqr(double a){return a*a;}
double Dist(double ax,double ay,double bx,double by){return sqrt(sqr(ax-bx)+sqr(ay-by));}
int main(){
    scanf("%d%lf%lf",&n,&d1,&d2);
    for(int i=1;i<=n;i++)scanf("%lf%lf%lf%lf",&ax[i],&ay[i],&bx[i],&by[i]);
    for(int i=1;i<=n;i++)dab[i]=Dist(ax[i],ay[i],bx[i],by[i]);
    for(int i=1;i<n;i++){
        dist[++tot]=dab[i];
        double X1=bx[i]-ax[i],Y1=by[i]-ay[i],X2=bx[i+1]-ax[i+1],Y2=by[i+1]-ay[i+1],ddist;//printf("%lf %lf %lf %lf\n",X1,Y1,X2,Y2);
        if(X1!=X2||Y1!=Y2)
            if(X2*(X2-X1)+Y2*(Y2-Y1)>0&&X1*(X1-X2)+Y1*(Y1-Y2)>0){//printf("QAQ\n");
                ddist=abs(X1*Y2-X2*Y1)/Dist(X1,Y1,X2,Y2);
                dist[++tot]=ddist;
            }
    }
    dist[++tot]=dab[n];
    //for(int i=1;i<=tot;i++)printf("%lf\n",dist[i]);
    seq[qwq=1]=1;
    for(int i=0;i<tot;i++){
        if((i==0||dist[i]>d1)&&dist[i+1]<=d1)seq[++qwq]=0;
        if((i==0||dist[i]<=d2)&&dist[i+1]>d2)seq[++qwq]=1;
    }//for(int i=1;i<=qwq;i++)printf("%d ",seq[i]);printf("\n");
    for(int i=1;i<qwq;i++)if(seq[i]&&!seq[i+1])++ans;
    printf("%d",ans);
    return 0;
}