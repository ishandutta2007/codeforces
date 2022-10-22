#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=4e5+10;
int n,q;char A[maxn];

int m,sa[maxn],rk[maxn],ht[maxn],tp[maxn],bf[maxn],buk[maxn],lg[maxn],st[18][maxn];
void radix_sort(){
  memset(buk,0,(m+1)<<2);
  rep(i,1,n)buk[bf[i]=rk[tp[i]]]++;
  rep(i,1,m)buk[i]+=buk[i-1];
  per(i,n,1)sa[buk[bf[i]]--]=tp[i];
}
void suffix_sort(){
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
int qmin(int l,int r){
  int k=lg[r-l+1];
  return min(st[k][l],st[k][r-(1<<k)+1]);
}

int main(){
  scanf("%d%d%s",&n,&q,A+1);
  suffix_sort();
  while(q--){
    static int st[maxn],lef[maxn],rig[maxn],X[maxn],Y[maxn],V[maxn],val[maxn];int top=0;
    int cx,cy;scanf("%d%d",&cx,&cy);int sz=cx+cy;
    rep(i,1,cx)scanf("%d",&X[i]),V[i]=X[i]=rk[X[i]];
    rep(i,1,cy)scanf("%d",&Y[i]),V[cx+i]=Y[i]=rk[Y[i]];
    sort(X+1,X+cx+1),sort(Y+1,Y+cy+1),sort(V+1,V+sz+1),sz=unique(V+1,V+sz+1)-V-1;
    ll ans=0;
    set<int>vis;
    rep(i,1,cx)vis.insert(X[i]);
    rep(i,1,cy)if(vis.count(Y[i]))ans+=n-sa[Y[i]]+1;
    set<int>visy;
    rep(i,1,cy)visy.insert(Y[i]);
    rep(i,2,sz)val[i]=qmin(V[i-1]+1,V[i]);
    st[0]=1;
    rep(i,2,sz){
      while(top&&val[st[top]]>val[i])top--;
      lef[i]=st[top]+1,st[++top]=i;
    }
    st[top=0]=sz+1;
    per(i,sz,2){
      while(top&&val[st[top]]>=val[i])top--;
      rig[i]=st[top]-1,st[++top]=i;
    }
//    printf("X : ");rep(i,1,cx)printf("%d%c",X[i],"\n "[i<iend]);
//    printf("Y : ");rep(i,1,cy)printf("%d%c",Y[i],"\n "[i<iend]);
//    printf("V : ");rep(i,1,sz)printf("%d%c",V[i],"\n "[i<iend]);
    rep(i,2,sz){
      ll c1=1ll*(upper_bound(X+1,X+cx+1,V[i-1])-lower_bound(X+1,X+cx+1,V[lef[i]-1]))*(upper_bound(Y+1,Y+cy+1,V[rig[i]])-lower_bound(Y+1,Y+cy+1,V[i]));
      ll c2=1ll*(upper_bound(X+1,X+cx+1,V[rig[i]])-lower_bound(X+1,X+cx+1,V[i]))*(upper_bound(Y+1,Y+cy+1,V[i-1])-lower_bound(Y+1,Y+cy+1,V[lef[i]-1]));
      ans+=1ll*val[i]*(c1+c2);
//      rep(l,lef[i],i)rep(r,i,rig[i]){
//        if((vis.count(V[l-1])&&visy.count(V[r])))ans+=val[i];
//        if((vis.count(V[r])&&visy.count(V[l-1])))ans+=val[i];
//      }
    }
//    rep(i,1,cx)rep(j,1,cy){
//      int l=X[i],r=Y[j];
//      if(l>r)swap(l,r);
//      if(l<r)ans+=qmin(l+1,r);
//    }
    printf("%lld\n",ans);
  }
  return 0;
}