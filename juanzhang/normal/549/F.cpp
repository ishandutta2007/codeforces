#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=3e5+10;
int n,k,A[maxn],st[maxn],lef[maxn],rig[maxn],sum[maxn];vector<int>pos[1000010],pos2[1000010];

int query(vector<int>&V,int l,int r){
  return upper_bound(V.begin(),V.end(),r)-lower_bound(V.begin(),V.end(),l);
}

int main(){
  cin>>n>>k;int top=0;
  rep(i,1,n){
    scanf("%d",A+i);
    while(top&&A[st[top]]<=A[i])top--;
    lef[i]=st[top]+1,st[++top]=i,sum[i]=(sum[i-1]+A[i])%k,pos[sum[i]].push_back(i),pos2[sum[i-1]].push_back(i);
  }
  st[0]=n+1,top=0;
  per(i,n,1){
    while(top&&A[st[top]]<A[i])top--;
    rig[i]=st[top]-1,st[++top]=i;
  }
  long long ans=0;
  rep(i,1,n){
//    rep(l,lef[i],i)rep(r,i,rig[i])ans+=(sum[r]-sum[l-1]-A[i]%k+k+k)%k==0;
    if(i-lef[i]<rig[i]-i){
      rep(j,lef[i],i){
        ans+=query(pos[(sum[j-1]+A[i])%k],i,rig[i]);
      }
    }else{
      rep(j,i,rig[i]){
        ans+=query(pos2[(sum[j]-A[i]%k+k)%k],lef[i],i);
      }
    }
  }
  cout<<ans-n<<endl;
  return 0;
}