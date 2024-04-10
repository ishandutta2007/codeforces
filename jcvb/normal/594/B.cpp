#include<cstdio>
#include<algorithm>
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
const db pi=acos(-1);
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
const int mo=1000000007;
const int inf=1061109567;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n,r,v;
int main()
{
    gn(n);gn(r);gn(v);
    while(n--){
        int p,q;
        gn(p);gn(q);
        db l=q-p;
        db one=2*pi*r;
        db cnt=floor(l/one);
        l-=one*cnt;
        db lef=0,rig=l*0.5;
        for (int i=0;i<70;i++){
            db mid=0.5*(lef+rig);
            db s=r*sin(mid/r)+mid;
            if(s<l*0.5)lef=mid;
            else rig=mid;
        }
        db ans=lef*2+one*cnt;
        printf("%.10lf\n",ans/v);
    }
    return 0;
}