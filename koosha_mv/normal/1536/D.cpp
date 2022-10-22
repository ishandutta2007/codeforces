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

const int N=2e6+99,mod=1e9+7;

int t,n,a[N];

int main(){
   cin>>t;
   while(t--){
      set<int> s;
      int ans=1;
      cin>>n;
      f(i,0,n){
         cin>>a[i];
         if(i){
            int u=a[i-1],v=a[i];
            if(u>v) swap(u,v);
            if(u!=*(s.rbegin()) && (*s.upper_bound(u))<v) ans=0;
         }
         s.insert(a[i]);
      }
      if(ans) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
   }
}