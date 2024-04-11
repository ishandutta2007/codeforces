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
 
const int N=5e5+9;

int n,m,q,ans[2];
ll res[N];
vector<int> v[2];
pair<int,int> p[N];
set<int> s[2];

int main(){
   cin>>n>>m>>q;
   s[0].insert(0);
   s[1].insert(0);
   s[0].insert(n);
   s[1].insert(m);
   v[0].pb(0);
   v[1].pb(0);
   v[0].pb(n);
   v[1].pb(m);
   f(i,0,q){
      char c;
      int x;
      cin>>c>>x;
      p[i]=mp((c=='H'),x);
      s[p[i].F].insert(p[i].S);
      v[p[i].F].pb(p[i].S);
   }
   f(i,0,2){
      sort(v[i].begin(),v[i].end());
      f(j,1,v[i].size())
         maxm(ans[i],v[i][j]-v[i][j-1]);
   }
   f_(i,q-1,0){
      res[i]=1ll*ans[0]*ans[1];
      int u=*s[p[i].F].upper_bound(p[i].S),v;
      v=*prev(s[p[i].F].lower_bound(p[i].S));
      maxm(ans[p[i].F],u-v);
      s[p[i].F].erase(p[i].S);
   }
   f(i,0,q)
      cout<<res[i]<<endl;
}