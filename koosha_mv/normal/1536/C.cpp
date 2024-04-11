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

const int N=5e5+99,mod=1e9+7;

int t,n,a[N],ans[N];
string s;

int main(){
   cin>>t;
   while(t--){
      map<pair<int,int> , int> mark;
      int d=0,k=0;
      cin>>n>>s;
      fill(ans,ans+n+1,1);
      f(i,0,n){
         d+=s[i]=='D';
         k+=s[i]=='K';
         int u=d/__gcd(d,k),v=k/__gcd(d,k);
         cout<<++mark[mp(u,v)]<<" ";
      }
      cout<<endl;
   }
}