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
 
const int N=105;
 
int n,x,c,q,last,win[2*N],mark[N];
vector<int> v;
 
int Win(int u,int v){
   if(u==n) return v;
   if(v==n) return u;
   else cout<<1<<" "<<u<<" "<<v<<endl;
   cin>>x;
   if(x) return u;
   return v;
}
bool ask(int u,int t){
   cout<<2<<" "<<u<<" "<<t<<" ";
   f(i,0,t) cout<<v[i]<<" ";
   cout<<endl;
   cin>>x;
   return x;
}
 
int main(){
   cin>>q;
   while(q--){
      c=0;
      v.clear();
      cin>>n;
      f(i,0,2*N) win[i]=n;
      f(i,n,2*n) win[i]=i-n;
      f_(i,n-1,0) win[i]=Win(win[i*2+0],win[i*2+1]);
      f(i,0,n){
         int u=win[1];
         v.pb(u);
         win[u+n]=n;
         for(int j=(u+n)/2;j;j/=2)
            win[j]=Win(win[j*2+0],win[j*2+1]);
      }
      last=n-1;
      f_(i,n-1,0){
         if(last>i) last--,c++;
         mark[v[i]]=c;
         while(ask(v[i],last) && last) last--;
      }
      cout<<3<<endl;
      f(i,0,n){
         f(j,0,n)
            cout<<(mark[i]>=mark[j]);
         cout<<endl;
      }
      cin>>x;
   }
}