#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef double db;
int n;
struct point{db x,y;}p[105];
db sqd(point &a,point &b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
point O(point A,point B,point C,db a,db b,db c){
    db ca=(b*b+c*c-a*a)/2/b/c;
    db cb=(a*a+c*c-b*b)/2/a/c;
    db cc=(a*a+b*b-c*c)/2/a/b;
    db s=a*ca+b*cb+c*cc;
    return (point){(a*ca*A.x+b*cb*B.x+c*cc*C.x)/s,(a*ca*A.y+b*cb*B.y+c*cc*C.y)/s};
}
int jud(point a,point b,point c,point d){
    db s[6];
    s[0]=sqd(a,b);
    s[1]=sqd(a,c);
    s[2]=sqd(a,d);
    s[3]=sqd(b,c);
    s[4]=sqd(b,d);
    s[5]=sqd(c,d);
    sort(s,s+6);
    if(fabs(s[0]-s[1])<eps && fabs(s[2]-s[3])<eps && fabs(s[4]-s[1]-s[2])<eps && fabs(s[5]-s[1]-s[2])<eps)return 1;
    else return 0;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    db ans=-1;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=j+1;k<=n;k++){
                db a,b,c;
                a=sqd(p[j],p[k]);
                b=sqd(p[i],p[k]);
                c=sqd(p[i],p[j]);
                if(a+b>c+eps && a+c>b+eps && b+c>a+eps){
                    point o=O(p[i],p[j],p[k],sqrt(a),sqrt(b),sqrt(c));
                    db ds=sqd(o,p[i]);
                    int bo=1;
                    for (int l=1;l<=n && bo;l++)if(sqd(p[l],o)<ds-eps)bo=0;
                    if(bo)ans=max(ans,sqrt(ds));
                }else if(fabs(a+b-c)<eps || fabs(a+c-b)<eps  || fabs(c+b-a)<eps){
                    int bo=0;point o;
                    for (int l=k+1;l<=n;l++)
                        if(jud(p[i],p[j],p[k],p[l])){
                            o=(point){(p[i].x+p[j].x+p[k].x+p[l].x)/4,(p[i].y+p[j].y+p[k].y+p[l].y)/4};
                            bo=1;
                            break;
                        }
                    if(bo){
                        db ds=sqd(o,p[i]);
                        for (int l=1;l<=n && bo;l++)if(sqd(p[l],o)<ds-eps)bo=0;
                        if(bo)ans=max(ans,sqrt(ds));
                    }
                }
            }
    if(ans<0)printf("-1\n");
    else printf("%.6lf\n",ans);
    return 0;
}