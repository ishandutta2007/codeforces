#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+9,Z=27;

int n,q,u,cnt[Z];
string t;
set<int> s,ind;
set<pair<int,int> > g[Z];
vector<pair<int,int> > ans;

int BIT[N];
void Add(int x,int val) { ++x;  while(x<=n)  {  BIT[x]+=val;  x+=(x&-x);  } }
int Get(int x) {  ++x;  int res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; } 

void Clear(){
   s.clear();
   ans.clear();
   ind.clear();
   f(i,0,Z){
      cnt[i]=0;
      g[i].clear();
   }
   fill(BIT,BIT+n+1,0);
}
int check(){
   int res=0,mx=0,x;
   f(i,0,Z){
      res+=(cnt[i]>0);
      if(cnt[i]>mx)  
         x=i,mx=cnt[i];
   }
   if(res>1) return x;
   return -1;
}
void do_it(pair<int,int> x){
   ans.pb(mp(Get(x.F+1),Get(x.S)));
   while(1){
      Add(*ind.lower_bound(x.F+1),-1);
      ind.erase(*ind.lower_bound(x.F+1));
      if(ind.lower_bound(x.F+1)==ind.end() || *ind.lower_bound(x.F+1)>x.S) break;
   }
}
void del(int u,int v){
   int x=t[u]-'a';
   g[x].erase(mp(u,v));
   x=t[v]-'a';
   g[x].erase(mp(u,v));
}
void XOX(){
   f(i,0,n)
      Add(i,1);
   while((u=check())!=-1){
      pair<int,int> p=*g[u].begin();
      g[u].erase(p);
      if(p.F==u) g[t[p.S]-'a'].erase(p);
      else g[t[p.F]-'a'].erase(p);
      
      do_it(p);
      cnt[t[p.F]-'a']--;
      cnt[t[p.S]-'a']--;
      del(p.F,p.S);
      if(s.lower_bound(p.F)!=s.begin()){
         del(*prev(s.lower_bound(p.F)),p.F);
      }
      if(s.upper_bound(p.S)!=s.end())
         del(p.S,*s.upper_bound(p.S));
      if(s.lower_bound(p.F)!=s.begin() && s.upper_bound(p.S)!=s.end()){
         int u=*prev(s.lower_bound(p.F));
			int v=*s.upper_bound(p.S);
         if(t[u]!=t[v]){
            g[t[u]-'a'].insert(mp(u,v));
            g[t[v]-'a'].insert(mp(u,v));
         }
      }
      s.erase(p.F);
      s.erase(p.S);
   }
}
void XoX(){
   vector<int> v;
   int last=0;
   while(ind.size()){
      v.pb(*ind.rbegin());
      ind.erase(*ind.rbegin());
   }
   f(i,0,v.size()){
      if(i==v.size()-1 || t[v[i]]==t[v[i+1]]){
         ans.pb(mp(Get(v[i]),Get(v[last])));
         last=i+1;
      }
   }
}
void P(){
   cout<<ans.size()<<'\n';
   f(i,0,ans.size())
      cout<<ans[i].F<<" "<<ans[i].S<<'\n';
}

int main(){
   cin>>q;
   f(Q,0,q){
      cin>>t;
      n=t.size();
      int last=-1;
      f(i,0,n-1){
         ind.insert(i);
         if(t[i]==t[i+1]){
            if(last!=-1){
               if(t[last]!=t[i]){
                  g[t[i]-'a'].insert(mp(last,i));
                  g[t[last]-'a'].insert(mp(last,i));
               }
            }
            s.insert(i);
            last=i;
            cnt[t[i]-'a']++;
         }
      }
      ind.insert(n-1);
      XOX();
      XoX();
      P();
      Clear();
   }
}