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
//const ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789
using namespace std;
int n;
map<int,int>mx,my;
int xtot=0,ytot=0;
struct node{
    int a,b,c,d,id;
}t[211111];
int cmpy(const node&a,const node&b){
    return a.b>b.b;
}
int cmpid(const node&a,const node&b){
    return a.id<b.id;
}
int up[211111];
int cur[211111]={0};

int seg[844444];
int I,V;
int l1,r1;

int gmi(int a,int b){
    return t[a].b>t[b].b?b:a;
}
void upd(int l,int r,int x){
    if(l==r){
        seg[x]=V;
    }else{
        int mid=l+r>>1;
        if(I<=mid)upd(l,mid,x<<1);
        else upd(mid+1,r,x<<1|1);
        seg[x]=gmi(seg[x<<1],seg[x<<1|1]);
    }
}
void query(int l,int r,int x){
    if(l1<=l && r<=r1){
        V=gmi(V,seg[x]);
    }else{
        int mid=l+r>>1;
        if(l1<=mid)query(l,mid,x<<1);
        if(r1>mid)query(mid+1,r,x<<1|1);
    }
}
int qu[211111],pre[211111],dis[211111],vis[211111]={0};
int del[211111]={0};
int p=0,q=0;

void print(int x){
    if(!x)return;
    print(pre[x]);
    printf("%d ",x);
}
int main()
{
    t[0].a=t[0].b=1111111111;
    gn(n);
    for (int i=1;i<=n;i++){
        gn(t[i].a);
        gn(t[i].b);
        gn(t[i].c);
        gn(t[i].d);
        t[i].id=i;
        mx[t[i].a];
        mx[t[i].c];
        my[t[i].b];
        my[t[i].d];
    }
    mx[0];
    my[0];
    for (map<int,int> :: iterator it=mx.begin();it!=mx.end();it++){
        it->second=++xtot;
    }
    for (map<int,int> :: iterator it=my.begin();it!=my.end();it++){
        it->second=++ytot;
    }
    for (int i=1;i<=n;i++){
        t[i].a=mx[t[i].a];
        t[i].c=mx[t[i].c];
        t[i].b=my[t[i].b];
        t[i].d=my[t[i].d];
    }

    sort(t+1,t+1+n,cmpy);
    for (int i=1;i<=n;i++){
        up[t[i].id]=cur[t[i].a];
        cur[t[i].a]=t[i].id;
    }
    sort(t+1,t+1+n,cmpid);
    for (int i=1;i<=xtot;i++)if(cur[i]){
        I=i;V=cur[i];
        upd(1,xtot,1);
    }


    for (int i=1;i<=n;i++)if(t[i].a==1 && t[i].b==1){
        vis[i]=1;
        qu[q++]=i;
    }
    while(p!=q){
        int u=qu[p++];
        l1=1,r1=t[u].c;
        while(1){
            V=0;
            query(1,xtot,1);
            if(del[V])continue;

            if(t[V].b>t[u].d)break;
        
            if(!vis[V]){
                vis[V]=1;
                pre[V]=u;
                qu[q++]=V;
                dis[V]=dis[u]+1;
            }

            del[V]=1;
            I=t[V].a,V=up[V];
            upd(1,xtot,1);
        }
    }
    if(!vis[n]){
        printf("-1\n");
    }else{
        printf("%d\n",dis[n]+1);
        print(n);
        printf("\n");
    }
    return 0;
}