#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<complex>
#include<iostream>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define dump(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
const int INF=5e8;
typedef pair<int,int> pi;
typedef complex<double> P;
P rotate(P a,double ang){
    return P(a.real()*cos(ang)+a.imag()*sin(ang),
            a.imag()*cos(ang)-a.real()*sin(ang));
}
bool solve(P a,P b,double r,double dst){
    double ang1=atan2(b.imag(),b.real());
    a=rotate(a,ang1);
    b=rotate(b,ang1);
    if(a.imag()<0) a.imag()=-a.imag();
    
    double len1=abs(a),len2=abs(b);
    double len3=sqrt(len1*len1-r*r),len4=sqrt(len2*len2-r*r);
    double theta1=atan2(len3,r),theta2=atan2(len4,r);
    double theta3=atan2(a.imag(),a.real());
    double sumlen;
    if(theta3<=theta1+theta2){
        sumlen=abs(a-b);
    }else sumlen=len3+len4+(theta3-theta1-theta2)*r;
    if(sumlen<=dst) return true;
    return false;
}

double PI=acos(-1.0);
int main(){
    double xp,yp,vp,x,y,v,r;
    scanf("%lf%lf%lf%lf%lf%lf%lf,",&xp,&yp,&vp,&x,&y,&v,&r);
    double lb=0,ub=1e6;
    P a(xp,yp),b(x,y);
    double angle_per_time=vp/(2*PI*abs(a))*2*PI;
    dump(angle_per_time);
    REP(hoge,60){
        double md=(ub+lb)/2;
        P a2=rotate(a,-angle_per_time*md);
        if(solve(a2,b,r,v*md)) ub=md;
        else lb=md;
    }
    printf("%.10f\n",lb);
    return 0;
}