#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

namespace SA{
  static const int maxn=4e5+10;
  char A[maxn];int bl[maxn];
  int n,m,sa[maxn],rk[maxn],ht[maxn],tp[maxn],bf[maxn],buk[maxn];
  void radix_sort(){
    memset(buk,0,(m+1)<<2);
    rep(i,1,n)buk[bf[i]=rk[tp[i]]]++;
    rep(i,1,m)buk[i]+=buk[i-1];
    per(i,n,1)sa[buk[bf[i]]--]=tp[i];
  }
  int lg[maxn],st[18][maxn];
  void build(int _n){
    n=_n;
    m=150;
    rep(i,1,n)rk[i]=A[i],tp[i]=i;
    radix_sort();
    for(int k=1;k<=n;k<<=1){
      int num=0;
      per(i,n,n-k+1)tp[++num]=i;
      rep(i,1,n)if(sa[i]>k)tp[++num]=sa[i]-k;
      radix_sort();
      swap(rk,tp),rk[sa[1]]=1,num=1;
      rep(i,2,n)rk[sa[i]]=num+=tp[sa[i]]!=tp[sa[i-1]]||tp[sa[i]+k]!=tp[sa[i-1]+k];
      if(n==num)break;
      m=num;
    }
    for(int i=1,j=0;i<=n;i++){
      if(j)j--;
      while(A[i+j]==A[sa[rk[i]-1]+j])j++;
      ht[rk[i]]=j;
    }
    rep(i,2,n)lg[i]=lg[i>>1]+1;
    rep(i,1,n)st[0][i]=ht[i];
    rep(i,1,17)rep(j,1,n-(1<<i)+1)st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
  }
  int query(int l,int r){
    int k=lg[r-l+1];
    return min(st[k][l],st[k][r-(1<<k)+1]);
  }
  int lcp(int i,int j){
    if(i==j)return n-i+1;
    i=rk[i],j=rk[j];
    if(i>j)swap(i,j);
    return query(i+1,j);
  }
  int query_lef(int pos,int len){
    int l=2,r=pos,ans=pos;
    while(l<=r){
      int mid=(l+r)/2;
      query(mid,pos)>=len?r=ans=mid-1:l=mid+1;
    }
    return ans;
  }
  int query_rig(int pos,int len){
    int l=pos+1,r=n,ans=pos;
    while(l<=r){
      int mid=(l+r)/2;
      query(pos+1,mid)>=len?l=(ans=mid)+1:r=mid-1;
    }
    return ans;
  }
}

const int maxn=4e5+10;

int n,q,pos[maxn],len[maxn];

#define mid ((l+r)>>1)

int tot,rt[maxn],ls[maxn*20],rs[maxn*20],sum[maxn*20];
void ins(int&k,int rt,int l,int r,int x){
  sum[k=++tot]=sum[rt]+1,ls[k]=ls[rt],rs[k]=rs[rt];
  if(l<r)x<=mid?ins(ls[k],ls[rt],l,mid,x):ins(rs[k],rs[rt],mid+1,r,x);
}
int query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return sum[k];
  int res=0;
  if(ql<=mid)res=query(ls[k],l,mid,ql,qr);
  if(qr>mid)res+=query(rs[k],mid+1,r,ql,qr);
  return res;
}

#undef mid

int main(){
  scanf("%d%d",&n,&q);
  int cur=1;
  rep(i,1,n){
    pos[i]=cur;
    static char str[maxn];
    scanf("%s",str+1);
    len[i]=strlen(str+1);
    rep(j,1,len[i])SA::bl[cur]=i,SA::A[cur++]=str[j];
    SA::A[cur++]='#';
  }
  SA::build(cur-1);
  rep(i,1,SA::n){
    rt[i]=rt[i-1];
    if(SA::bl[SA::sa[i]]){
      ins(rt[i],rt[i-1],1,n,SA::bl[SA::sa[i]]);
    }
  }
  while(q--){
    int l,r,x;
    scanf("%d%d%d",&l,&r,&x);
    int sz=len[x];x=SA::rk[pos[x]];
    int lef=SA::query_lef(x,sz);
    int rig=SA::query_rig(x,sz);
    printf("%d\n",query(rt[rig],1,n,l,r)-query(rt[lef-1],1,n,l,r));
  }
  return 0;
}