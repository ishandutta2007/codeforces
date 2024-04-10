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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const int mo=1000000007;


const int sta=5555555;
const int hashmod=1001003;
struct has{
    ll S[sta];int V[sta],next[sta];
    int head[hashmod];
    int tot;
    void cl(){
        tot=0;
        memset(head,-1,sizeof(head));
    }
    int push(ll s,int v){
        int t=s%hashmod;
        for (int i=head[t];~i;i=next[i])if(S[i]==s){
            return V[i]=max(V[i],v);
        }
        S[tot]=s;V[tot]=v;next[tot]=head[t];head[t]=tot++;
        return v;
    }
    int find(ll s,int &ans){
        int t=s%hashmod;
        for (int i=head[t];~i;i=next[i])if(S[i]==s){
            ans=V[i];
            return 1;
        }
        return 0;
    }
}ha;
int n;

struct node{
    int l,m,w;
}a[30];
node lef[2555555],rig[2555555];
int ltot=0,rtot=0;
char s[55];

int tl,tmm,tw;
int dfs2(int cur,int le,int ri,int l,int m,int w,node*arr,int&tot){
    if(cur==ri+1){
        if(l==tl && m==tmm && w==tw){
            for (int i=le;i<=ri;i++){
                if(s[i]=='W')printf("ML\n");
                if(s[i]=='M')printf("WL\n");
                if(s[i]=='L')printf("WM\n");
            }
            return 1;
        }else return 0;
    }else{
        s[cur]='W';
        if(dfs2(cur+1,le,ri,l+a[cur].l,m+a[cur].m,w,arr,tot))return 1;
        s[cur]='M';
        if(dfs2(cur+1,le,ri,l+a[cur].l,m,w+a[cur].w,arr,tot))return 1;
        s[cur]='L';
        if(dfs2(cur+1,le,ri,l,m+a[cur].m,w+a[cur].w,arr,tot))return 1;
        return 0;
    }
}
void dfs(int cur,int le,int ri,int l,int m,int w,node*arr,int&tot){
    if(cur==ri+1){
        node ne;ne=(node){l,m,w};
        arr[++tot]=ne;
    }else{
        //s[cur]='W';
        dfs(cur+1,le,ri,l+a[cur].l,m+a[cur].m,w,arr,tot);
        //s[cur]='M';
        dfs(cur+1,le,ri,l+a[cur].l,m,w+a[cur].w,arr,tot);
        //s[cur]='L';
        dfs(cur+1,le,ri,l,m+a[cur].m,w+a[cur].w,arr,tot);
    }
}

ll f(int x,int y){
    return 1ll*(x+1000000000)*1000000000+(y+1000000000);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d%d%d",&a[i].l,&a[i].m,&a[i].w);

    int mid=(1+n)>>1;
    dfs(1,1,mid,0,0,0,lef,ltot);
    dfs(mid+1,mid+1,n,0,0,0,rig,rtot);

    ha.cl();

    for (int i=1;i<=rtot;i++){
        ha.push(f(rig[i].m-rig[i].l,rig[i].w-rig[i].m),rig[i].l);
    }
    int ma=-2000000000,l1,m1,w1,l2;
    for (int i=1;i<=ltot;i++){
        ll fi=f(lef[i].l-lef[i].m,lef[i].m-lef[i].w);
        int an=0;
        if(ha.find(fi,an)){
            if(an+lef[i].l>ma){
                ma=an+lef[i].l;
                l1=lef[i].l;
                m1=lef[i].m;
                w1=lef[i].w;
                l2=an;
            }
        }
    }
    if(ma==-2000000000){
        printf("Impossible\n");
        return 0;
    }else{
        tl=l1,tmm=m1,tw=w1;
        dfs2(1,1,mid,0,0,0,lef,ltot);
        tl=l2,tmm=l1+l2-m1,tw=l1+l2-w1;
        dfs2(mid+1,mid+1,n,0,0,0,rig,rtot);
    }
    return 0;
}