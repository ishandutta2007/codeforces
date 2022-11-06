#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
#define MOD 1000000007
struct SegmentTree{
    int b[2][2],a[2][2];
} tree[401010];
int n,Testing,i,opt,l,r,vv,B[10][10],C[10][10];
long long a[1001010];
void MulB(){
    for (int i=0;i<2;i++)
       for (int j=0;j<2;j++)
           C[i][j]=0;
    for (int k=0;k<2;k++)
       for (int i=0;i<2;i++)
          for (int j=0;j<2;j++)
             C[i][j]=(C[i][j]+1ll*B[i][k]*B[k][j]) % MOD;
    for (int i=0;i<2;i++)
       for (int j=0;j<2;j++)
           B[i][j]=C[i][j];
}
void MulA(int x){
    for (int i=0;i<2;i++)
       for (int j=0;j<2;j++)
           C[i][j]=0;
    for (int k=0;k<2;k++)
       for (int i=0;i<2;i++)
          for (int j=0;j<2;j++)
             C[i][j]=(C[i][j]+1ll*tree[x].a[i][k]*B[k][j]) % MOD;
    for (int i=0;i<2;i++)
       for (int j=0;j<2;j++)
           tree[x].a[i][j]=C[i][j];
}
void MulC(int x){
    for (int i=0;i<2;i++)
       for (int j=0;j<2;j++)
           C[i][j]=0;
    for (int k=0;k<2;k++)
       for (int i=0;i<2;i++)
          for (int j=0;j<2;j++)
             C[i][j]=(C[i][j]+1ll*tree[x].b[i][k]*B[k][j]) % MOD;
    for (int i=0;i<2;i++)
       for (int j=0;j<2;j++)
           tree[x].b[i][j]=C[i][j];
}
void pushup(int x){
    for (int i=0;i<2;i++)
       for (int j=0;j<2;j++)
           tree[x].a[i][j]=(tree[x<<1].a[i][j]+tree[x<<1|1].a[i][j]) % MOD;
}
void pushdown(int x){
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) B[i][j]=tree[x].b[i][j];
    MulC(x<<1);MulC(x<<1|1);MulA(x<<1);MulA(x<<1|1);
    tree[x].b[0][0]=1;tree[x].b[0][1]=0;tree[x].b[1][0]=0;tree[x].b[1][1]=1;
}
void build(int x,int l,int r){
    tree[x].b[0][0]=1;tree[x].b[0][1]=0;tree[x].b[1][0]=0;tree[x].b[1][1]=1;
    if (l==r){
        B[0][0]=0;B[0][1]=1;B[1][0]=1;B[1][1]=1;
        tree[x].a[0][0]=1;tree[x].a[0][1]=0;tree[x].a[1][0]=0;tree[x].a[1][1]=1;
        int final=a[l];
        for (;final;final>>=1,MulB())
             if (final&1) MulA(x);
        return ;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);build(x<<1|1,mid+1,r);
    pushup(x);
}
void modify(int x,int l,int r,int tl,int tr,int val){
    if ((l>=tl)&&(r<=tr)){
        B[0][0]=0;B[0][1]=1;B[1][0]=1;B[1][1]=1;
        int final=val;
        for (;final;final>>=1,MulB())
             if (final&1) MulA(x),MulC(x);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(x);
    if (tl<=mid) modify(x<<1,l,mid,tl,tr,val);
    if (tr>mid) modify(x<<1|1,mid+1,r,tl,tr,val);
    pushup(x);
}
int query(int x,int l,int r,int tl,int tr){
    if ((l>=tl)&&(r<=tr)) return tree[x].a[1][0];
    int mid=(l+r)>>1;
    long long ans=0;
    pushdown(x);
    if (tl<=mid) ans=ans+query(x<<1,l,mid,tl,tr);
    if (tr>mid) ans=ans+query(x<<1|1,mid+1,r,tl,tr);
    ans=ans % MOD;
    pushup(x);
    return ans;
}
int main()
{
    n=read();Testing=read();
    for (i=1;i<=n;i++) a[i]=read();
    build(1,1,n);
    for (;Testing;Testing--){
         opt=read();
         if (opt==1){
            l=read();r=read();vv=read();
            modify(1,1,n,l,r,vv);
         }
         if (opt==2) l=read(),r=read(),printf("%d\n",query(1,1,n,l,r));
    }
return 0;
}