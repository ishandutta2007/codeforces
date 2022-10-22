#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99,M=1e6+99;

int n,m,a[N],p[N],pos[N],mark[N],ans[M],seg[N<<2],cnt[N<<2],lz[N<<2],tz[N<<2];
vector<pair<int,int>> Q[N];

void shift(int id,int l,int r);

pair<int,int> operator + (pair<int,int> p1,pair<int,int> p2){
	return {p1.F+p2.F,p1.S+p2.S};
}
void add(int L,int R,int val0,int val1,int id=1,int l=1,int r=n+1){
	if(L==R || R<=l || r<=L) return ;
	if(L<=l && r<=R){
		seg[id]+=val0*(r-l);
		cnt[id]+=val1*(r-l);
		lz[id]+=val0;
		tz[id]+=val1;
		return ;
	}
	int mid=(l+r)>>1;
	shift(id,l,r);
	add(L,R,val0,val1,id<<1,l,mid);
	add(L,R,val0,val1,id<<1|1,mid,r);
	seg[id]=seg[id<<1]+seg[id<<1|1];
	cnt[id]=cnt[id<<1]+cnt[id<<1|1];
}
pair<int,int> get(int L,int R,int id=1,int l=1,int r=n+1){
	if(r<=L || R<=l) return {0,0};
	if(L<=l && r<=R){
		return {seg[id],cnt[id]};
	}
	int mid=(l+r)>>1;
	shift(id,l,r);
	return get(L,R,id<<1,l,mid)+get(L,R,id<<1|1,mid,r);
}
void shift(int id,int l,int r){
	int mid=(l+r)>>1;
	add(l,mid,lz[id],tz[id],id<<1,l,mid);
	add(mid,r,lz[id],tz[id],id<<1|1,mid,r);
	lz[id]=tz[id]=0;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,1,n+1) cin>>p[i],pos[p[i]]=i;
	f(i,0,m){
		int l,r;
		cin>>l>>r;
		Q[r].pb({l,i});
	}
	vector<int> vec;
	p[0]=n+1;
	vec.pb(0);
	f(i,1,n+1){
		for(int j=1;p[i]*j<=n;j++){
			if(i<pos[j] || j==p[i]) continue ;
			int val=max(a[p[i]*j],min(pos[j],pos[p[i]*j]));
			if(a[p[i]*j]<val && mark[pos[p[i]*j]]){
				add(a[p[i]*j]+1,val+1,-i,+1);
			}
			a[p[i]*j]=val;
		}
		while(p[vec.back()]<p[i]){
			int id=vec.back();
			vec.pop_back();
			mark[id]=0;
			add(vec.back()+1,a[p[id]]+1,+i,-1);
		}
		maxm(a[p[i]],vec.back());
		add(vec.back()+1,a[p[i]]+1,-i,+1);
		vec.pb(i);
		mark[i]=1;
		for(auto q : Q[i]){
			pair<int,int> p=get(q.F,i+1);
			ans[q.S]=p.F+(i+1)*p.S;
		}
	}
	f(i,0,m) cout<<ans[i]<<" ";
}
/*
3 1
1 2 3
1 3
*/