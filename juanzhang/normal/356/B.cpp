#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=1e6+10;
int n,m,ct[maxn][26];ll X,Y;char A[maxn],B[maxn];

vector<int>vec[maxn];
int tot,bl[maxn],pos[maxn],sum[maxn][26];

int main(){
  cin>>X>>Y;
  scanf("%s%s",A,B);
  n=strlen(A);
  m=strlen(B);
  ll ans=0;
  static bool vis[maxn];
  rep(i,0,m-1){
    int cur=i;
    while(!vis[cur]){
      bl[cur]=tot,pos[cur]=vec[tot].size(),vec[tot].push_back(cur);
      vis[cur]=1,cur=(cur+n)%m;
    }
    int lst[26];
    memset(lst,0,sizeof lst);
    for(int x:vec[tot]){
      lst[B[x]-'a']++;
      memcpy(ct[x],lst,sizeof lst);
    }
    memcpy(sum[tot],lst,sizeof lst);
    tot++;
  }
  rep(i,0,n-1){
    int t=i%m;
    int sz=vec[bl[t]].size();
    ll p=X/sz,q=X%sz;
    ans+=p*sum[bl[t]][A[i]-'a'];
    if(!q)continue;
    int l=pos[t];
    int r=pos[t]+q-1;
    r%=sz;
    if(l>r){
      swap(l,r);
      l++,r--;
    }
    if(l<=r){
      ans+=ct[vec[bl[t]][r]][A[i]-'a'];
      if(l){
        ans-=ct[vec[bl[t]][l-1]][A[i]-'a'];
      }
    }
//    rep(k,0,q-1)ans+=A[i]==B[vec[bl[t]][(pos[t]+k)%sz]];

//    rep(k,0,X-1){
//      ans+=A[i]==B[(k*n+i)%m];
//    }
  }
  cout<<X*n-ans<<endl;
  return 0;
}