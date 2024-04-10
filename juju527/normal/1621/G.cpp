#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
int n,a[maxn],pos[maxn];
int pre[maxn],suf[maxn],f[maxn];
pair<int,int> p[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline int sub(int x){return (x<0)?x+mod:x;}
int t[maxn],lowbit[maxn];
void update(int x,int v){while(x<=n)t[x]=add(t[x]+v),x+=lowbit[x];return ;}
int query(int x){int res=0;while(x)res=add(res+t[x]),x-=lowbit[x];return res;}
bool cmp(int i,int j){return a[i]<a[j];}
vector<int> bl[maxn];
int main(){
    int T;
    T=read();
    for(int i=1;i<=2e5;i++)lowbit[i]=i&-i;
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)p[i]=make_pair(read(),-i);
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++)a[-p[i].se]=i;
        for(int i=1;i<=n;i++)t[i]=0;
        for(int i=1;i<=n;i++){
            pre[i]=add(query(a[i]-1)+1);
            update(a[i],pre[i]);
        }
        for(int i=1;i<=n;i++)t[i]=0;
        int sum=0;
        for(int i=n;i>=1;i--){
            suf[i]=add(sub(sum-query(a[i]))+1);
            sum=add(sum+suf[i]);
            update(a[i],suf[i]);
        }
        int sufmx=0,len=0;
        for(int i=n;i>=1;i--)if(a[i]>sufmx)pos[++len]=i,sufmx=a[i];
        for(int i=1;i<=len;i++)bl[i].clear();
        for(int i=n;i>=1;i--){
            int x=lower_bound(pos+1,pos+len+1,i,cmp)-pos;
            bl[x].push_back(i);
        }
        for(int i=1;i<=n;i++)t[i]=f[i]=0;
        for(int i=1;i<=len;i++){
            int sum=0;
            for(int j=0;j<bl[i].size();j++){
                int x=bl[i][j];
                f[x]=sub(sum-query(a[x]));
                if(x==pos[i])f[x]=1;
                sum=add(sum+f[x]);
                update(a[x],f[x]);
            }
            for(int j=0;j<bl[i].size();j++)update(a[bl[i][j]],sub(-f[bl[i][j]]));
        }
        int res=0;
        for(int i=1;i<=n;i++)res=add(res+1ll*pre[i]*sub(suf[i]-f[i])%mod);
        printf("%d\n",res);
    }
    return 0;
}