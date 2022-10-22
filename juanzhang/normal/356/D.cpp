#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef pair<int,int>pii;
const int maxn=70010;
int n,s,A[maxn];
bitset<maxn>P,Q,bit[maxn/4];
bool vis[maxn];

int ps=1;

void divide(int l,int r,int goal,int lev){
//  printf("(%d %d %d %d)\n",l,r,goal,lev);
  if(l>r)return;
  if(l==r)return vis[l]=A[l]==goal,void();
  if(lev==2){
    rep(i,0,r-l+1)bit[i].reset();
    bit[0].set(0);
    rep(i,1,r-l+1)if(l+i-1!=ps)bit[i]=bit[i-1]|(bit[i-1]<<A[l+i-1]);else bit[i]=bit[i-1]<<A[l+i-1];
    int cur=0;
    per(i,r-l+1,1){
      if(l+i-1==ps){
        vis[l+i-1]=1,cur+=A[ps];
      }else{
        int x=A[l+i-1];
        if(cur+x<=goal&&bit[i-1][goal-cur-x]){
          cur+=x,vis[l+i-1]=1;
        }
      }
    }
    return;
  }
  int mid=(l+r)/2;
  P.reset(),Q.reset();
  P.set(0),Q.set(0);
  rep(i,l,mid)if(i!=ps)P|=P<<A[i];else P<<=A[i];
  rep(i,mid+1,r)if(i!=ps)Q|=Q<<A[i];else Q<<=A[i];
  rep(i,0,goal){
    if(P[i]&&Q[goal-i]){
      divide(l,mid,i,lev+1);
      divide(mid+1,r,goal-i,lev+1);
      return;
    }
  }
}

int main(){
  cin>>n>>s;
  rep(i,1,n){
    scanf("%d",A+i);
    if(A[i]>A[ps])ps=i;
  }
  divide(1,n,s,0);
  int sum=0;
  rep(i,1,n)if(vis[i])sum+=A[i];
  if(sum!=s)return puts("-1"),0;
  vector<pii>vec;
  rep(i,1,n)if(!vis[i]||i==ps){
    vec.push_back({A[i],i});
  }
  sort(vec.begin(),vec.end(),greater<pii>());
  static int nxt[maxn];
  rep(i,1,vec.size()-1){
    nxt[vec[i-1].second]=vec[i].second;
  }
  rep(i,1,n){
    if(nxt[i]){
      printf("%d 1 %d\n",A[i]-A[nxt[i]],nxt[i]);
    }else{
      printf("%d 0\n",A[i]);
    }
  }
  return 0;
}