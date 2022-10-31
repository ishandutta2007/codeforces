#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[50005],nmsl[50005];
vector<int> p[50005];

#define N 1000

int __gcd(int u,int v) {
  int shift;
  if (u == 0) return v;
  if (v == 0) return u;
  shift = __builtin_ctz(u | v);
  u >>= __builtin_ctz(u);
  do {
    unsigned m;
    v >>= __builtin_ctz(v);
    v -= u;
    m = (int)v >> 31;
    u += v & m;
    v = (v + m) ^ m;
  } while (v != 0);
  return u << shift;
}

struct SB{
	#define md ((l+r)/2)
	#define ls (id*2)
	#define rs (ls+1)
	
	int mp[N+5][50005];
	ll f[200005],t[200005],k;
	void init(int id,int l,int r){
		if(id>N)return;
		for(int i=l;i<=r;i++)for(auto j:p[nmsl[i]]){
			if(mp[id][j])mp[id][j]=min(mp[id][j],nmsl[i]/j);
			else mp[id][j]=nmsl[i]/j;
		}
		init(ls,l,md); init(rs,md+1,r);
	}
	void init2(int id,int l,int r){
		if(l==r){
			f[id]=1ll*(a[l]/__gcd(a[l],nmsl[l]))*(nmsl[l]/__gcd(a[l],nmsl[l]));
			return;
		}
		init2(ls,l,md); init2(rs,md+1,r);
		f[id]=min(f[ls],f[rs]);
	}
	void fuck(int id,int l,int r,int w){
		t[id]=w;
		f[id]=1e18;
		if(id>N){
			for(int i=l;i<=r;i++){
				f[id]=min(f[id],1ll*(w/__gcd(nmsl[i],w))*(nmsl[i]/__gcd(nmsl[i],w)));
			}
			return;
		}
		else{
			for(auto i:p[w]){
				if(mp[id][i]){
					f[id]=min(f[id],1ll*(w/i)*mp[id][i]);
				}
			}
		}
	}
	void add(int id,int l,int r,int x,int y,int w){
		if(x<=l&&r<=y){
			fuck(id,l,r,w);
			return;
		}
		if(t[id]){
			fuck(ls,l,md,t[id]);
			fuck(rs,md+1,r,t[id]);
			t[id]=0;
		}
		if(x<=md)add(ls,l,md,x,y,w);
		if(y>md)add(rs,md+1,r,x,y,w);
		f[id]=min(f[ls],f[rs]);
	}
	ll get(int id,int l,int r,int x,int y){
		ll res=1e18;
		if(x<=l&&r<=y)return f[id];
		if(t[id]){
			fuck(ls,l,md,t[id]);
			fuck(rs,md+1,r,t[id]);
			t[id]=0;
		}
		if(x<=md)res=min(res,get(ls,l,md,x,y));
		if(y>md)res=min(res,get(rs,md+1,r,x,y));
		return res;
	}
}sb;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(i=50000;i>=1;i--){
		for(j=i;j<=50000;j+=i)p[j].push_back(i);
	}
	cin>>n>>t;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>nmsl[i];
	sb.init(1,1,n);
	sb.init2(1,1,n);
	while(t--){
		int ty,l,r,w;
		cin>>ty;
		if(ty==1){
			cin>>l>>r>>w;
			sb.add(1,1,n,l,r,w);
		}
		else{
			cin>>l>>r;
			cout<<sb.get(1,1,n,l,r)<<'\n';
		}
	}
}//