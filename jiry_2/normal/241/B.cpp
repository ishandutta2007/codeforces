#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct tree{
    int a[32],l,r,size;
}t[1600000];
struct atom{
    int l,r;
}x[51000],y[51000];
int len,n,deep=30,ans,mo=1e9+7;
long long m;
void insert(int k1,int k2,int k3){
    t[k1].size++; //cout<<k1<<" "<<k2<<" "<<k3<<endl;
    for (int i=0;i<30;i++) if (k2&(1<<i)) t[k1].a[i]++; if (k3==0) return;
    if ((k2&(1<<k3-1))==0){
        if (t[k1].l==0) t[k1].l=++len; insert(t[k1].l,k2,k3-1);
    } else {
        if (t[k1].r==0) t[k1].r=++len; insert(t[k1].r,k2,k3-1);
    }
}
void findans(int k2,int k3){
    if (k2==0){
        ans=(ans+1ll*m*k3)%mo; return;
    }
    long long now=0; 
    for (int i=1;i<=len;i++) if (x[i].l!=x[i].r) now=now+1ll*t[t[x[i].l].l].size*t[t[x[i].r].r].size+1ll*t[t[x[i].l].r].size*t[t[x[i].r].l].size; else now=now+1ll*t[t[x[i].l].l].size*t[t[x[i].r].r].size;
    //cout<<k2<<" "<<k3<<" "<<len<<" "<<ans<<" "<<m<<" "<<now<<endl;
    //for (int i=1;i<=len;i++) cout<<x[i].l<<" "<<x[i].r<<endl;
    if (now>=m){
        int k4=0;
        for (int i=1;i<=len;i++){
            if (t[x[i].l].l&&t[x[i].r].r) y[++k4]=(atom){t[x[i].l].l,t[x[i].r].r};
            if (t[x[i].l].r&&t[x[i].r].l&&x[i].l!=x[i].r) y[++k4]=(atom){t[x[i].l].r,t[x[i].r].l};
        }
        for (int i=1;i<=k4;i++) x[i]=y[i]; len=k4;
        findans(k2-1,k3+(1<<k2-1));
    } else {
        m-=now;
        for (int i=1;i<=len;i++)
            for (int j=0;j<30;j++)
                if (x[i].l!=x[i].r){
                    ans=(ans+(1ll*t[t[x[i].l].l].a[j]*(t[t[x[i].r].r].size-t[t[x[i].r].r].a[j])%mo+1ll*t[t[x[i].l].r].a[j]*(t[t[x[i].r].l].size-t[t[x[i].r].l].a[j]))*(1ll<<j)%mo)%mo;
                    ans=(ans+(1ll*t[t[x[i].r].l].a[j]*(t[t[x[i].l].r].size-t[t[x[i].l].r].a[j])%mo+1ll*t[t[x[i].r].r].a[j]*(t[t[x[i].l].l].size-t[t[x[i].l].l].a[j]))*(1ll<<j)%mo)%mo;
                } else ans=(ans+(1ll*t[t[x[i].l].l].a[j]*(t[t[x[i].r].r].size-t[t[x[i].r].r].a[j])%mo+1ll*t[t[x[i].l].r].a[j]*(t[t[x[i].r].l].size-t[t[x[i].r].l].a[j]))*(1ll<<j)%mo)%mo;
        int k4=0;
        for (int i=1;i<=len;i++){
            if (t[x[i].l].l&&t[x[i].r].l) y[++k4]=(atom){t[x[i].l].l,t[x[i].r].l};
            if (t[x[i].l].r&&t[x[i].r].r) y[++k4]=(atom){t[x[i].l].r,t[x[i].r].r};
        }
        for (int i=1;i<=k4;i++) x[i]=y[i]; len=k4;
        findans(k2-1,k3);
    }
}
int main(){
    memset(t,0x00,sizeof t); scanf("%d%I64d",&n,&m); len++; for (int i=1;i<=n;i++){int k1; scanf("%d",&k1); insert(1,k1,deep);}
    len=1; x[1]=(atom){1,1}; findans(deep,0); cout<<ans<<endl; return 0;
}