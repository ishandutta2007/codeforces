#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define sqr(x) ((x)*(x))
double eps=0.0000005, fi=(sqrt(5.0)-1)/2;
double x[100],y[100],z[100];
double xx,yy,zz;
int n;

double max(double a, double b) {
        return a-b>eps ? a : b;
}

double min(double a, double b) {
        return a-b<eps ? a : b;
}

double d(double x, double y, double z) {
        return (sqr(x)+sqr(y)+sqr(z));
}

double calc(double x1, double y1, double z1) {
        double ans=-1;
        for (int i=0; i<n; i++) {
                ans=max(ans,d(x1-x[i],y1-y[i],z1-z[i]));
        }
        return ans;
}

double calcz(double x, double y) {
        double l=-10000,r=10000;
        double f1=calc(x,y,l+(r-l)*(1-fi));
        double f2=calc(x,y,l+(r-l)*fi);
        while (max(f2,f1)-min(f1,f2)>eps || r-l>eps) {
                if (f1-f2<0) {
                        r=l+(r-l)*fi;
                        f2=f1;
                        f1=calc(x,y,l+(r-l)*(1-fi));
                }
                else {
                        l=l+(r-l)*(1-fi);
                        f1=f2;
                        f2=calc(x,y,l+(r-l)*fi);
                }
        }
        zz=(r+l)/2;
        return calc(x,y,zz);
}

double calcy(double x){
        double l=-10000,r=10000;
        double f1=calcz(x,l+(r-l)*(1-fi));
        double f2=calcz(x,l+(r-l)*fi);
        while (max(f2,f1)-min(f1,f2)>eps || r-l>eps) {
                if (f1-f2<0) {
                        r=l+(r-l)*fi;
                        f2=f1;
                        f1=calcz(x,l+(r-l)*(1-fi));
                }
                else {
                        l=l+(r-l)*(1-fi);
                        f1=f2;
                        f2=calcz(x,l+(r-l)*fi);
                }
        }
        yy=(r+l)/2;
        return calcz(x,yy);
}

void calcx() {
        double l=-10000,r=10000;
        double f1=calcy(l+(r-l)*(1-fi));
        double f2=calcy(l+(r-l)*fi);
        while (max(f2,f1)-min(f1,f2)>eps || r-l>eps) {
                if (f1-f2<0) {
                        r=l+(r-l)*fi;
                        f2=f1;
                        f1=calcy(l+(r-l)*(1-fi));
                }
                else {
                        l=l+(r-l)*(1-fi);
                        f1=f2;
                        f2=calcy(l+(r-l)*fi);
                }
        }
        xx=(r+l)/2;
}
int main()
{
//      freopen("input.txt","r",stdin);
//      freopen("output.txt","w",stdout);
        cin >> n;
        for (int i=0; i<n; i++) cin >> x[i] >> y[i] >> z[i];
        calcx();
        cout << xx << ' ' << yy << ' ' << zz;
        return 0;
}