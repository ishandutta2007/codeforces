#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d,f[110000],g[110000];
int ans,Ans[110000];
ll a[110000],tmp[110000]; int cnt;
int tree1[110000],tree2[110000];
char Getchar(){
    static char now[1<<20],*S,*T;
    if (T==S){
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
int read(){
    int x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
ll readl(){
    ll x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
int getmax(int a,int b){
    if (f[a]>f[b]) return a;
    return b;
}
void add1(int x,int y){
    for (;x<=cnt;x+=x&-x) tree1[x]=getmax(tree1[x],y);
}
void add2(int x,int y){
    for (;x;x-=x&-x) tree2[x]=getmax(tree2[x],y);
}
int query1(int x){
    int res=0;
    for (;x;x-=x&-x) res=getmax(res,tree1[x]);
    return res;
}
int query2(int x){
    int res=0;
    for (;x<=cnt;x+=x&-x) res=getmax(res,tree2[x]);
    return res;
}
int main(){
    n=read(); d=read();
    for (int i=1;i<=n;i++){ a[i]=readl(); tmp[++cnt]=a[i];}
    sort(tmp+1,tmp+cnt+1); cnt=unique(tmp+1,tmp+cnt+1)-tmp-1;
    int x,y,pos,j;
    for (int i=1;i<=n;i++){
        x=upper_bound(tmp+1,tmp+cnt+1,a[i]-d)-tmp-1;
        y=lower_bound(tmp+1,tmp+cnt+1,a[i]+d)-tmp;
        j=getmax(query1(x),query2(y));
        f[i]=f[j]+1; g[i]=j;
        pos=lower_bound(tmp+1,tmp+cnt+1,a[i])-tmp;
        add1(pos,i); add2(pos,i);
    }
    int res=0;
    for (int i=1;i<=n;i++) res=getmax(res,i);
    printf("%d\n",f[res]);
    while (res){
    	Ans[++ans]=res;
        res=g[res];
    }
    while (ans) printf("%d ",Ans[ans--]);
    return 0;
}