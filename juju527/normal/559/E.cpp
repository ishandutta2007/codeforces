#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105,inf=1e9;
struct line{
    int id,l,r;
    bool operator <(line i)const{return l<i.l;}
};
line l[2*maxn];
ll f[2*maxn][2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++){
        int p,len;
        p=read();len=read();
        l[i]=(line){i,p-len,p};
        l[i+n]=(line){i,p,p+len};
    }
    int m=2*n;
    sort(l+1,l+m+1);
    for(int i=1;i<=m;i++)f[0][i]=l[i].r-l[i].l;
    l[0]=(line){0,-inf,-inf};
    ll res=0;
    for(int i=0;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            for(int k=j+1;k<=m;k++){
                if(l[k].id==l[i].id||l[k].id==l[j].id)continue;
                if(l[k].r<=l[j].r||l[k].l==l[j].l||l[i].r>=l[k].l)continue;
                ll cur=f[i][j]+l[k].r-l[k].l;
                if(l[k].l<l[j].r)cur-=l[j].r-l[k].l;
                f[j][k]=max(f[j][k],cur);
            }
            res=max(res,f[i][j]);
        }
    }
    printf("%lld\n",res);
    return 0;
}