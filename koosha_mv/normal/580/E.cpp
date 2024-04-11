#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,base=37,mod=1e9+7;

int n,t,q1,q2,ans,len,a[N],FT[N],def[N],seg[N],lazy[N];
string s;

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

void merge(int id,int l,int r){
	int mid=(l+r)/2;
	seg[id]=(1ll*seg[id*2+1]*pow(base,mid-l,mod)+seg[id*2+0])%mod;
}
void build(int id,int l,int r){
	def[id]=FT[r-l-1];
	if(l+1==r){
		seg[id]=s[l]-'0';
		return ;
	}
	int mid=(l+r)/2;
	build(id*2+0,l,mid);
	build(id*2+1,mid,r);
	merge(id,l,r);
}
void shift(int id){
	if(lazy[id]==-1) return ;
   seg[id*2+0]=1ll*def[id*2+0]*lazy[id]%mod;
   seg[id*2+1]=1ll*def[id*2+1]*lazy[id]%mod;
   lazy[id*2+0]=lazy[id];
   lazy[id*2+1]=lazy[id];
   lazy[id]=-1;
}
void add(int L,int R,int val,int id=1, int l=0,int r=n){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
   	seg[id]=1ll*def[id]*val%mod;
      lazy[id]=val;
      return ;   
   }
   int mid=(l+r)>>1;
   shift(id);
   add(L,R,val,id*2+0,l,mid);
   add(L,R,val,id*2+1,mid,r);
   merge(id,l,r);
}
int query(int L,int R,int id=1,int l=0,int r=n){
   if(r<=L || R<=l) return 0;
   if(L<=l && r<=R){
   	int res=1ll*seg[id]*pow(base,len,mod)%mod;
   	len+=r-l;
      return res;
   }
   shift(id);
   int mid=(l+r)>>1;
   return (query(L,R,id*2+0,l,mid)+query(L,R,id*2+1,mid,r))%mod;
}
int get(int l,int r){
	len=0;
	return query(l,r);
}

int main(){
	fill(lazy,lazy+N,-1);
	FT[0]=1;
	f(i,1,N){
		FT[i]=(1ll*FT[i-1]*base+1)%mod;
	}
	cin>>n>>q1>>q2>>s;
	build(1,0,n);
	f(i,0,q1+q2){
		int type,l,r;
		cin>>type;
		if(type==1){
			char c;
			cin>>l>>r>>c;
			l--;
			add(l,r,c-'0');
		}
		else{
			int d;
			cin>>l>>r>>d;
			l--;
			if(get(l,r-d)==get(l+d,r)){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
}
/*
3 1 0
112
2 1 3 0
*/