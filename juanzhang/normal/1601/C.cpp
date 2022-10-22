#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=2e6+10;
int n,m,A[maxn],B[maxn];

int vtt,dat[maxn];

#define mid ((l+r)>>1)

int val[maxn<<2],tag[maxn<<2];
void build(int k,int l,int r){
  tag[k]=0,val[k]=l;
  if(l<r)build(k<<1,l,mid),build(k<<1|1,mid+1,r);
}
void add(int k,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr)return tag[k]+=x,val[k]+=x,void();
  if(ql<=mid)add(k<<1,l,mid,ql,qr,x);
  if(qr>mid)add(k<<1|1,mid+1,r,ql,qr,x);
  val[k]=tag[k]+min(val[k<<1],val[k<<1|1]);
}

#undef mid

int c[maxn];
void add(int pos){
  for(;pos<=vtt;pos+=pos&-pos)c[pos]++;
}
int query(int pos){
  int res=0;for(;pos;pos&=pos-1)res+=c[pos];return res;
}

vector<int>vec[maxn];

int main(){
  ios::sync_with_stdio(0);
  int T;cin>>T;while(T--){
    cin>>n>>m;
    rep(i,1,n)cin>>A[i],dat[i]=A[i];
    rep(i,1,m)cin>>B[i],dat[n+i]=B[i];
    sort(B+1,B+m+1);
    vtt=n+m;
    sort(dat+1,dat+vtt+1);
    vtt=unique(dat+1,dat+vtt+1)-dat-1;
    rep(i,1,n)A[i]=lower_bound(dat+1,dat+vtt+1,A[i])-dat,vec[A[i]].push_back(i);
    rep(i,1,m)B[i]=lower_bound(dat+1,dat+vtt+1,B[i])-dat;
    ll ans=0;
    memset(c,0,(vtt+1)*4);
    rep(i,1,n)ans+=i-1-query(A[i]),add(A[i]);
//    putchar('#');rep(i,1,n)printf("%d%c",A[i],"\n "[i<iend]);
//    putchar('#');rep(i,1,m)printf("%d%c",B[i],"\n "[i<iend]);
    build(1,0,n);
    for(int i=1,j=0;i<=m;i++){
      while(j<B[i]){
        for(int p:vec[j]){
          add(1,0,n,0,p-1,1);
        }
        j++;
        for(int p:vec[j]){
          add(1,0,n,p,n,-1);
        }
      }
      ans+=val[1];
    }
    cout<<ans<<endl;
    rep(i,1,vtt)vec[i].clear();
  }
  return 0;
}