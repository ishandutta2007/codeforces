#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int mo=1000000007;


int xx1,yy1,xx2,yy2;
int vmax,t;
int vx1,vy1,vx2,vy2;
const db eps=1e-10;

inline db dist(db xx1,db yy1,db xx2,db yy2){
    return sqrt((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2));
}

void get(db &x,db &y,db tt){
    db t1=min(tt,1.0*t);
    db t2=max(tt-t,0.0);
    x=xx2-vx1*t1-vx2*t2;
    y=yy2-vy1*t1-vy2*t2;
}
int main()
{
    cin>>xx1>>yy1>>xx2>>yy2;
    cin>>vmax>>t;
    cin>>vx1>>vy1>>vx2>>vy2;

    db l=0.0,r=1e10;
    int tes=200;
    while(tes--){
        db mid=(l+r)/2;
        db x,y;
        get(x,y,mid);
        db d=dist(xx1,yy1,x,y);
        if(d<=mid*vmax){
            r=mid;
        }else
            l=mid;
    }
    printf("%.10lf\n",l);
    return 0;
}