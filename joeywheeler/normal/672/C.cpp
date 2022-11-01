#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

double ans;
double x[100005];
double y[100005];
double d[100005];

double ax, ay, bx, by, tx, ty;
int n;

double dst(double a,double b,double c, double d) {
    return sqrt(pow(a-c,2)+pow(b-d,2));
}

int main() {
    scanf("%lf%lf%lf%lf%lf%lf",
            &ax,&ay,
            &bx,&by,
            &tx,&ty
         );
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%lf%lf",x+i,y+i);
        ans += dst(x[i],y[i],tx,ty)*2;
    }
    vector<pair<double,int> > v1;
    vector<pair<double,int> > v2;
    v1.emplace_back(0,-1);
    v2.emplace_back(0,-1);
    FO(i,0,n) {
        v1.emplace_back(dst(x[i],y[i],ax,ay)-dst(x[i],y[i],tx,ty),i);
        v2.emplace_back(dst(x[i],y[i],bx,by)-dst(x[i],y[i],tx,ty),i);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    double mnadd = 1e15;
    FO(i,0,min(sz(v1),5)) {
        FO(j,0,min(sz(v2),5)) {
            if (v1[i].second != v2[j].second) {
                mnadd = min(mnadd,
                        v1[i].first+v2[j].first);
            }
        }
    }
    printf("%.10lf\n", ans+mnadd);
}