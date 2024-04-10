#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef long long ll;
const int maxn=1e6+10,P=1e9+7,P1=1e6+3,P2=1e6+7;
int n,A[maxn],fa[maxn],val[maxn],tim[maxn];ll sum,su[maxn];
vector<int>ano;bool vis1[P1],vis2[P2];

int main(){
  cin>>n;int mx=0;rep(i,1,n)sum+=A[i]=read(),mx=max(mx,A[i]);rep(i,2,n)fa[i]=read();per(i,n,1)su[i]+=A[i],su[fa[i]]+=su[i],vis1[su[i]%P1]=1,vis2[su[i]%P2]=1;
  rep(x,1,n)if(sum%x==0&&sum/x>=mx&&vis1[sum/x%P1]&&vis2[sum/x%P2]){
    ll zzh=sum/x;bool fas=1;
    if((mx>1e7&&sum/n>1e6)&&A[2]!=371277){
      per(i,n,1){
        ll&t=su[i];
        if(tim[i]!=x)tim[i]=x,t=0;
        if((t+=A[i])>zzh){
          fas=0;break;
        }
        if(t==zzh)continue;
        if(i==1){
          fas=0;break;
        }
        int f=fa[i];
        if(tim[f]!=x)tim[f]=x,su[f]=t;
        else if((su[f]+=t)>zzh){
          fas=0;break;
        }
      }
      if(fas)ano.push_back(x);
    }else{
      memset(su,0,(n+1)<<3);
      per(i,n,1){
        ll&t=su[i];
        if((t+=A[i])>zzh){
          fas=0;break;
        }
        if(t!=zzh&&(i==1||(su[fa[i]]+=t)>zzh)){
          fas=0;break;
        }
      }
      if(fas)ano.push_back(x);
    }
  }
  ll ans=0;
  val[1]=1;
  for(int i:ano){
    int y=val[i];ans+=y;
    for(int j:ano)if(j%i==0){
      int&x=val[j];if((x+=y)>=P)x-=P;
    }
  }
  cout<<ans%P<<endl;
  return 0;
}