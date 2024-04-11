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
#define sz(x) ((int) x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e5+999,S=1100,inf=1e9+99;

int n,m,q,last,a[N],b[N],s[N],ok[N],lupd[N];
vector<int> vec[N],pfx[N],sfx[N];

int ptr(int x){
	if(s[x]==0) return inf;
	return (b[x]+s[x]-1)/s[x];
}
void build(int id){
	sort(all(vec[id]),[&](int u,int v){ return ptr(u)<ptr(v); });	
	pfx[id].resize(sz(vec[id]));
	sfx[id].resize(sz(vec[id]));
	f(i,0,vec[id].size()){
		pfx[id][i]=b[vec[id][i]];
		if(i>0) pfx[id][i]+=pfx[id][i-1];
	}
	f_(i,vec[id].size()-1,0){
		sfx[id][i]=s[vec[id][i]];
		if(i+1<sfx[id].size()) sfx[id][i]+=sfx[id][i+1];
	}
}
int calc(int id,int t){
	int l=-1,r=vec[id].size();
	while(l+1<r){
		int mid=(l+r)>>1,x=vec[id][mid];
		if(ptr(x)<=t) l=mid;
		else r=mid;
	}
	return (l==-1 ? 0 : pfx[id][l])+(r==sz(sfx[id]) ? 0 : sfx[id][r])*t;
}
int upd(int id,int l,int r,int t){
	int ans=0;
	f(i,id*S,id*S+S){
		a[i]=min(a[i]+s[i]*(t-lupd[id]),b[i]);
		if(l<=i && i<r) ans+=a[i],a[i]=0;
	}
	ok[id]=0;
	lupd[id]=t;
	return ans;
}
int query(int id,int t){
	int ans=0;
	if(ok[id]==0){
		f(i,id*S,id*S+S){
			ans+=min(a[i]+s[i]*(t-lupd[id]),b[i]);
			a[i]=0;
		}
	}
	else{
		ans=calc(id,t-lupd[id]);
	}
	ok[id]=1;
	lupd[id]=t;
	return ans;
}
int get(int l,int r,int t){
	int ans=0;
	if(l/S==r/S){
		return upd(l/S,l,r,t);
	}
	if(l%S){
		ans+=upd(l/S,l,l/S*S+S,t);	
		l=l/S*S+S;
	}
	if(r%S){
		ans+=upd(r/S,r/S*S,r,t);
		r=r/S*S;
	}
	for(;l<r;l+=S){
		ans+=query(l/S,t);
	}
	return ans;
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>a[i]>>b[i]>>s[i];
	}
	for(int i=0;i<n;i+=S){
		f(j,i,min(n,i+S)) vec[i/S].pb(j);
		build(i/S);
	}
	cin>>q;
	while(q--){
		int t,l,r;
		cin>>t>>l>>r; l--;
		cout<<get(l,r,t)<<endl;
	}
}