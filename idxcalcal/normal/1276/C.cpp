#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
const int N=4e5+5;
int n,a[N],vl[N],cnt[N],sig=0;
vector<int>ans[N];
pii pt[N];
inline int find(int x) { return lower_bound(vl+1,vl+sig+1,x)-vl; }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  for(ri i=1;i<=n;++i) a[i]=vl[i]=read();
  sort(vl+1,vl+n+1),sig=unique(vl+1,vl+n+1)-vl-1;
  for(ri i=1;i<=n;++i) ++cnt[find(a[i])];
  for(ri i=1;i<=sig;++i) pt[i]=pii(cnt[i],vl[i]);
  sort(pt+1,pt+sig+1);
  int res=0,pos1=0,pos2=0;
  for(ri curlen,_len,ps,len=1;len*len<=n;++len) {
    ps=sig,curlen=0;
    _len=0;
    while(1) {
      while(ps&&curlen<len) {
         curlen+=min(pt[ps].fi,len);
         --ps;
      }
      if(curlen>=len) {
        curlen-=len,++_len;
        if(_len>=len&&res<len*_len) {
          res=len*_len;
          pos1=len,pos2=_len;
        }
      }
      else break;
    }
  }
  cout<<res<<'\n';
  cout<<pos2<<' '<<pos1<<'\n';
  for(ri i=1;i<=pos2;++i) ans[i].resize(pos1+2);
  int ps=sig,curlen=0,len=pos1,_len=0;
    _len=0;
    queue<int>q;
    while(1) {
      while(ps&&curlen<len) {
         curlen+=min(pt[ps].fi,len);
         for(ri i=1;i<=min(pt[ps].fi,len);++i) q.push(pt[ps].se);
         --ps;
      }
      if(curlen>=len) {
        curlen-=len,++_len;
        for(ri x=1,y=_len;x<=pos1;++x,y=y==pos2?1:y+1) ans[y][x]=q.front(),q.pop();
      }
      else break;
    }
  for(ri i=1;i<=pos2;++i,puts("")) for(ri j=1;j<=pos1;++j) cout<<ans[i][j]<<' ';
  return 0;
}