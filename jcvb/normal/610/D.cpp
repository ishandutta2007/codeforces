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
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
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
int mo=1000000007;
int inf=1061109567;
db eps=1e-6;
//ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789
int n;
struct seg{
    int x1,y1,x2,y2;
}s[111111];
seg v[111111],h[111111];
seg vn[111111];int ntot=0;
int vtot=0,htot=0;
int cmpx(const seg&a,const seg&b){
    if(a.x1==b.x1)return a.y1<b.y1;
    return a.x1<b.x1;
}
int cmpy(const seg&a,const seg&b){
    if(a.y1==b.y1)return a.x1<b.x1;
    return a.y1<b.y1;
}

struct node{
    int x,y,sg;
}tt[222222];int ttot=0;



int cmpnode(const node&a,const node&b){
    return a.x<b.x;
}
struct nnode{int ch[2],sz,v,fix;}t[1000005];int ndtot=0;
int root=0;
void rot(int &x,int f){
    int y=t[x].ch[!f];
    t[x].ch[!f]=t[y].ch[f];
    t[y].ch[f]=x;
    t[y].sz=t[x].sz;
    t[x].sz=t[t[x].ch[0]].sz+t[t[x].ch[1]].sz+1;
    x=y;
}
void ins(int &x,int v){
    if(x==0){
        x=++ndtot;
        t[x].ch[0]=t[x].ch[1]=0;
        t[x].sz=1;
        t[x].fix=rand();
        t[x].v=v;
    }else{
        int f=v>=t[x].v;
        ins(t[x].ch[f],v);
        t[x].sz++;
        if(t[t[x].ch[f]].fix<t[x].fix)rot(x,!f);
    }
}
void del(int &x){
    if(!t[x].ch[0] && !t[x].ch[1])x=0;
    else{
        int f=!t[x].ch[0] || t[x].ch[1]&&t[t[x].ch[1]].fix<t[t[x].ch[0]].fix;
        rot(x,!f);
        t[x].sz--;
        del(t[x].ch[!f]);
    }
}
void del_num(int &x,int v){
    if(t[x].v==v)del(x);
    else{
        int f=v>=t[x].v;
        t[x].sz--;
        del_num(t[x].ch[f],v);
    }
}
int rk(int v){
    int x=root;int ans=0;
    while(x){
        if(t[x].v>=v)x=t[x].ch[0];
        else{
            ans+=t[t[x].ch[0]].sz+1;
            x=t[x].ch[1];
        }
    }
    return ans+1;
}
int main()
{
    gn(n);
    for (int i=1;i<=n;i++){
        gn(s[i].x1);
        gn(s[i].y1);
        gn(s[i].x2);
        gn(s[i].y2);
        if(s[i].x1>s[i].x2)swap(s[i].x1,s[i].x2);
        if(s[i].y1>s[i].y2)swap(s[i].y1,s[i].y2);
        if(s[i].x1==s[i].x2){
            v[++vtot]=s[i];
        }else h[++htot]=s[i];
    }
    sort(h+1,h+1+htot,cmpy);

    ll sum=0;
    for (int i=1,j;i<=htot;i=j){
        for (j=i;j<=htot && h[j].y1==h[i].y1;j++);

        int far=-inf;
        for (int k=i;k<j;k++){
            if(h[k].x1>far){
                if(far!=-inf)tt[++ttot]=(node){far+1,h[i].y1,-1};
                tt[++ttot]=(node){h[k].x1,h[i].y1,+1};
                far=max(far,h[k].x2);
            }else{
                far=max(far,h[k].x2);
            }
        }
        tt[++ttot]=(node){far+1,h[i].y1,-1};
    }
    for (int i=1;i<=ttot;i++)sum-=tt[i].x*tt[i].sg;

    sort(tt+1,tt+1+ttot,cmpnode);

    sort(v+1,v+1+vtot,cmpx);

    for (int i=1,j;i<=vtot;i=j){
        for (j=i;j<=vtot && v[j].x1==v[i].x1;j++);

        int far=-inf,st=-inf;
        for (int k=i;k<j;k++){
            if(v[k].y1>far){
                if(far!=-inf)vn[++ntot]=(seg){v[i].x1,st,v[i].x1,far};
                st=v[k].y1;
                far=max(far,v[k].y2);
            }else{
                far=max(far,v[k].y2);
            }
        }
        vn[++ntot]=(seg){v[i].x1,st,v[i].x1,far};
    }

    sort(vn+1,vn+1+ntot,cmpx);

    int cur=1;
    for (int i=1;i<=ntot;i++){
        while(cur<=ttot && tt[cur].x<=vn[i].x1){
            if(tt[cur].sg==1){
                ins(root,tt[cur].y);
            }else{
                del_num(root,tt[cur].y);
            }
            cur++;
        }
        int coin = rk(vn[i].y2+1)-rk(vn[i].y1);
        sum+=vn[i].y2-vn[i].y1+1 - coin;
    }
    cout<<sum<<endl;
    return 0;
}