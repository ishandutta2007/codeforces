#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 
#define mp make_pair 
#define ll long long
#define pii pair<double,double>

using namespace std;
const long double pi = 3.1415926535897932384626434;
const double eps = 1e-9;
int n;
double x,y;
pii a[333333];


int main(){
//        freopen("input","r",stdin);
  //      freopen("output","w",stdout);

        scanf("%d%lf%lf",&n,&x,&y);
        double Min = 1e18,Max = 0;
        for(int i = 0;i < n;i++) {
        	scanf("%lf%lf",&a[i].f,&a[i].s);
        	a[i].f -= x;
        	a[i].s -= y;
        	double z = a[i].f*a[i].f + a[i].s*a[i].s;
        	if(Max + eps < z) Max = z;
        	if(Min > sqrt(z) + eps) Min = sqrt(z);
        }
        a[n] = a[0];
        for (int i = 0;i < n;i++) {
        	double d1 = a[i + 1].f*a[i + 1].f + a[i + 1].s*a[i + 1].s;
        	double d2 = a[i].f*a[i].f + a[i].s*a[i].s;
        	double d3 = (a[i + 1].f - a[i].f)*(a[i + 1].f - a[i].f) + (a[i + 1].s - a[i].s)*(a[i + 1].s - a[i].s);

        	if(d1 > d2 + d3 + eps   ||   d2 > d1 + d3 + eps) continue;


		double A = a[i + 1].s - a[i].s;
		double B = a[i].f - a[i + 1].f;
		double C = a[i].s*a[i + 1].f - a[i].f*a[i + 1].s;
		double d = fabs(C)/sqrt(A*A + B*B);
		if(Min > d + eps) Min = d;        	
        }
        long double ans = pi*(0.0 + Max - Min*Min);
        printf("%.9lf",(double)(ans));

	return 0;
}