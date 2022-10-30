// Hydro submission #61f4b84837cee20376bcc240@1643427912539
#include<bits/stdc++.h>
#define seg int p,int l,int r
#define mid (l+r>>1)
#define lid p<<1,l,mid
#define rid p<<1|1,mid+1,r
using namespace std;
const int N=3e4+5;
struct mat{int cnt[2][2];}Fib,F[N];
struct segtree{int s;mat Cnt;}tr[N<<2];
int mod;
mat cnt[N];
void clear(mat &a){
    a.cnt[0][0]=a.cnt[1][1]=1;
    a.cnt[1][0]=a.cnt[0][1]=0;
}
mat operator*(const mat &a,const mat &b){
    mat ans;
    memset(ans.cnt,0,sizeof(ans.cnt));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            long long S=0;
            for(int k=0;k<2;k++)S=S+a.cnt[i][k]*b.cnt[k][j];
            ans.cnt[i][j]=S%mod;
        }    
    return ans;
}
mat operator+(const mat &a,const mat &b){
    mat ans;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)ans.cnt[i][j]=(a.cnt[i][j]+b.cnt[i][j])%mod;
    return ans;
}
mat operator*(int a,mat b){
    mat ans;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)ans.cnt[i][j]=a*b.cnt[i][j]%mod;
    return ans;
}
void change(seg,int x,int z){
    if(l==r){
        tr[p].s=(z>=0?1:0);
        tr[p].Cnt=max(z,0)*Fib;
        return;
    }
    if(x<=mid)change(lid,x,z);
    else change(rid,x,z);
    tr[p].Cnt=tr[p<<1].Cnt+tr[p<<1|1].Cnt*F[tr[p<<1].s];
    tr[p].s=tr[p<<1].s+tr[p<<1|1].s;
}
int s[N],rk[N],n,a[N],b[N],id[N],Q,ans[N];
struct que{int l,r,id;}q[N];
void add(int x){
    s[rk[x]]++;
    if(s[rk[x]]==1)change(1,1,n,rk[x],a[x]);
}
void del(int x){
    s[rk[x]]--;
    if(s[rk[x]]==0)change(1,1,n,rk[x],-1);
}
int main(){
    scanf("%d%d",&n,&mod);
    Fib.cnt[0][0]=1,Fib.cnt[0][1]=1;
    Fib.cnt[1][0]=1;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    clear(F[0]);
    for(int i=1;i<=n;i++)F[i]=F[i-1]*Fib;
    for(int i=1;i<=n;i++)rk[i]=lower_bound(b+1,b+n+1,a[i])-b;
    for(int i=1;i<=n;i++)a[i]%=mod;
    scanf("%d",&Q);
    int S=sqrt(n);
    for(int i=1;i<=n;i++)id[i]=(i-1)/S+1;
    for(int i=1;i<=Q;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    sort(q+1,q+Q+1,[](que a,que b){if(id[a.l]!=id[b.l])return a.l<b.l;return (id[a.l]&1?a.r<b.r:a.r>b.r);});
    int L=1,R=0;
    for(int i=1;i<=Q;i++){
        while(R<q[i].r)add(++R);
        while(L>q[i].l)add(--L);
        while(R>q[i].r)del(R--);
        while(L<q[i].l)del(L++);
        ans[q[i].id]=tr[1].Cnt.cnt[0][1];
    }
    for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
}