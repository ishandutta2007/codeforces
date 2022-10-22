#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e6+99;

int n,t,p[N],q[N],seg[N],lazy[N];

int merge(int u,int v){
	return max(u,v);
}
void shift(int id){
   seg[id*2+0]+=lazy[id];
   seg[id*2+1]+=lazy[id];
   lazy[id*2+0]+=lazy[id];
   lazy[id*2+1]+=lazy[id];
   lazy[id]=0;
}
void add(int L,int R,int val,int id=1, int l=1,int r=n+1){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]+=val;
      seg[id]+=val;
      return ;   
   }
   int mid=(l+r)>>1;
   shift(id);
   add(L,R,val,id*2+0,l,mid);
   add(L,R,val,id*2+1,mid,r);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
int query(int L,int R,int id=1,int l=1,int r=n+1){
   if(r<=L || R<=l) return -0;
   if(L<=l && r<=R){
      return seg[id];
   }
   shift(id);
   int mid=(l+r)>>1;
   return merge(query(L,R,id*2+0,l,mid),query(L,R,id*2+1,mid,r));
}

int main(){
	cin>>n;
	f(i,1,n+1){
		int x;
		cin>>x;
		p[x]=i;
	}
	f(i,1,n+1){
		cin>>q[i];
	}
	int ans=n+1;
	f(i,1,n+1){
		while(seg[1]<=0){
			add(1,p[ans-1]+1,1);
			ans--;
		}
		add(1,q[i]+1,-1);
		cout<<ans<<" ";
	}
}