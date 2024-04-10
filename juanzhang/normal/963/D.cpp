#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=2e5+10;
int n,q,ans[maxn];char S[maxn],T[maxn];queue<int>mat[maxn];

struct Querys{
  int pos,len,tid,x;
}Q[maxn];

const int P1=1e9+7,P2=1e9+9,B1=2333,B2=51111;
int pw1[maxn],pw2[maxn];
struct Hnode{
  int v1,v2;
  Hnode(){}
  Hnode(int x,int y):v1(x),v2(y){}
  Hnode app(int c){
    return Hnode((1ll*B1*v1+c)%P1,(1ll*B2*v2+c)%P2);
  }
  ll get(){
    return 1ll*v1*P2+v2;
  }
}dat[maxn],A[maxn];
Hnode query(Hnode*S,int l,int r){
  return Hnode((S[r].v1+1ll*(P1-S[l-1].v1)*pw1[r-l+1])%P1,(S[r].v2+1ll*(P2-S[l-1].v2)*pw2[r-l+1])%P2);
}

const int P=1e5+3;
int h[P],nxt[maxn];ll key[maxn];
int find(ll x){
  for(int i=h[x%P];i;i=nxt[i])if(key[i]==x)return i;
  return -1;
}
void ins(ll x,int id){
  int&H=h[x%P];nxt[id]=H,key[id]=x,H=id;
}

int main(){
  scanf("%s%d",S+1,&q),n=strlen(S+1);
  rep(i,1,q){
    Q[i].pos=Q[i-1].pos+Q[i-1].len+1,ans[i]=1e9,scanf("%d%s",&Q[i].x,T+Q[i].pos),Q[i].tid=i,Q[i].len=strlen(T+Q[i].pos);
  }
  pw1[0]=pw2[0]=1;
  rep(i,1,n)A[i]=A[i-1].app(S[i]);
  rep(i,1,maxn-1)pw1[i]=1ll*B1*pw1[i-1]%P1,pw2[i]=1ll*B2*pw2[i-1]%P2,dat[i]=dat[i-1].app(T[i]);
  sort(Q+1,Q+q+1,[](Querys X,Querys Y){
    return X.len<Y.len;
  });
  rep(l,1,q){
    int r=l,len=Q[l].len;
    while(r<q&&Q[r+1].len==len)r++;
    memset(h,0,sizeof h);
    rep(i,l,r){
      ins(query(dat,Q[i].pos,Q[i].pos+len-1).get(),i);
    }
    rep(i,1,n-len+1){
      int id=find(query(A,i,i+len-1).get());
      if(id==-1)continue;
//      printf("(%d) (%d %d)\n",Q[id].tid,i,i+len-1);
      auto&V=mat[id];
      V.push(i);
      if((int)V.size()>Q[id].x)V.pop();
      if((int)V.size()==Q[id].x)ans[Q[id].tid]=min(ans[Q[id].tid],i-V.front()+len);
    }
    l=r;
  }
  rep(i,1,q)printf("%d\n",ans[i]>n?-1:ans[i]);
  return 0;
}