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
 
const int N=2e5+99;

int n,t,mx,ans,a[N],b[N],seg[4*N],lazy[4*N];

void shift(int id){
   seg[id*2+0]+=lazy[id];
   seg[id*2+1]+=lazy[id];
   lazy[id*2+0]+=lazy[id];
   lazy[id*2+1]+=lazy[id];
   lazy[id]=0;
}
void add(int id, int L, int R, int l, int r, int val){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]+=val;
      seg[id]+=val;
      return ;   
   }
   int mid=(l+r)>>1;
   shift(id);
   add(id*2+0,L,R,l,mid,val);
   add(id*2+1,L,R,mid,r,val);
   seg[id]=max(seg[id*2+0],seg[id*2+1]);
}
int query(int id, int L, int R, int l, int r){
   if(r<=L || R<=l) return 0;
   if(L<=l && r<=R){
      return seg[id];
   }
   shift(id);
   int mid=(l+r)>>1;
   return max(query(id*2+0,L,R,l,mid),query(id*2+1,L,R,mid,r));
}

int main(){
   cin>>t;
   while(t--){
      set<int> s;
      int mv=1;
      ans=0;
      cin>>n;
      f(i,1,n+1){
         int x;
         cin>>x;
         a[x]=i;
         s.insert(i);
         if(x!=i) mv=0;
      }
      f(i,1,n*4+10) seg[i]=lazy[i]=0;
      f(i,1,n){
         int res;
         s.erase(a[i]);
         add(1,a[i],a[i]+1,1,n+1,a[i]);
         add(1,1,a[i],1,n+1,1);
         add(1,a[i],n+1,1,n+1,-1);
         res=query(1,*s.begin(),n+1,1,n+1);
         if((res&1)!=(i&1))
            res++;
         maxm(ans,res);
      }
      if(mv) cout<<0<<endl;
      else cout<<ans<<endl;
   }
}