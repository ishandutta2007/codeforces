#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef pair<double,double>pdd;
const int mn=1e6+10;
double inf=1e300;
struct line{
    double a,b,c;
};
struct circle{
    double x,y,r;
};
pdd intersect(line a,line b){
    try{
        return {(a.b*b.c-b.b*a.c)/(b.b*a.a-a.b*b.a),(a.a*b.c-b.a*a.c)/(b.a*a.b-a.a*b.b)};
    }catch(exception e){
        return {inf,inf};
    }
}
pair<pdd,pdd> intersect(circle a,circle b){
    try {
        double dx = b.x - a.x, dy = b.y - a.y, d = hypot(dx, dy);
        double dif = (a.r * a.r - b.r * b.r) / d, aa = (d + dif) / 2, s = sqrt(a.r * a.r - aa * aa);
        dx/=d,dy/=d;
        return {{a.x+dx*aa-dy*s,a.y+dy*aa+dx*s},{a.x+dx*aa+dy*s,a.y+dy*aa-dx*s}};
    }catch(exception e){
        return {{inf,inf},{inf,inf}};
    }
}
double sco=-1;
pdd bes={inf,inf};
double eps =1e-11;
double x1,y11,r1,x2,r2,y2,x3,y3,r3;
void test(pdd p){
    double aaa=r1/hypot(p.first-x1,p.second-y11);
    double bbb=r2/hypot(p.first-x2,p.second-y2);
    double ccc=r3/hypot(p.first-x3,p.second-y3);
    if(abs(aaa-bbb)>eps||abs(bbb-ccc)>eps)return;
    if(aaa>sco+eps)sco=aaa,bes=p;
}
pdd go(pdd a,pdd b,double r){
    return {a.first+(b.first-a.first)*r,a.second+(b.second-a.second)*r};
}
int main(){
    cin>>x1>>y11>>r1>>x2>>y2>>r2>>x3>>y3>>r3;
    if(r1==r2&&r2==r3){
        line A={x2-x1,y2-y11,(x1-x2)*(x1+x2)/2+(y11-y2)*(y11+y2)/2};
        line B={x3-x2,y3-y2,(x2-x3)*(x2+x3)/2+(y2-y3)*(y2+y3)/2};
        pdd p=intersect(A,B);
        test(p);
    }
    else{
        if(r1==r2)swap(r2,r3),swap(x2,x3),swap(y2,y3);
        else if(r2==r3)swap(r2,r1),swap(x2,x1),swap(y2,y11);
        double ra=r2/r1,rb=r3/r2,da=hypot(x2-x1,y2-y11),db=hypot(x3-x2,y3-y2);
        auto pa=go(go({x1,y11},{x2,y2},1/(ra+1)),go({x1,y11},{x2,y2},1/(1-ra)),0.5);
        circle A={pa.first,pa.second,0.5*da*(1/(ra+1)-1/(1-ra))};
        auto pb=go(go({x2,y2},{x3,y3},1/(rb+1)),go({x2,y2},{x3,y3},1/(1-rb)),0.5);
        circle B={pb.first,pb.second,0.5*db*(1/(rb+1)-1/(1-rb))};
        auto p=intersect(A,B);
        test(p.first),test(p.second);
    }
    if(bes.first<inf*0.00001)printf("%.10lf %.10lf",bes.first,bes.second);
}