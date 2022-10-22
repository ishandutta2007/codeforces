#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=42,K=11;

int n,k,cnt,mark[N],nw[K];
vector<ll> v[K],mask[K];

void do_it(ll u,int x){
   //cout<<x<<" : "<<u<<endl;
   f(i,0,nw[x]+1){
      int cnt=i+__builtin_popcountll(u&mask[x].back());
      v[x+1].pb((u&(1ll<<n)-1-mask[x].back())|mask[x][cnt]);
   }   
}

int main(){
   cin>>n>>k;
   f(i,0,k){
      int x,u;
      ll msk=0;
      mask[i].pb(0);
      cin>>x;
      f(j,0,x){
         cin>>u;
         u--;
         msk|=(1ll<<u);
         mask[i].pb(msk);
         if(!mark[u]){
            cnt++;
            nw[i]++;
            mark[u]=1;
         }
      }
   }
   v[0].pb(0);
   f(i,0,k){
      f(j,0,v[i].size()){
         do_it(v[i][j],i);
      }
   }
   if(n!=cnt && n>1) return cout<<"REJECTED"<<endl,0;
   f(i,0,v[k].size()){
      int cnt=__builtin_popcountll(v[k][i]);
      if((1ll<<cnt)-1!=v[k][i])
         return cout<<"REJECTED"<<endl,0;
   }
   cout<<"ACCEPTED"<<endl;
}