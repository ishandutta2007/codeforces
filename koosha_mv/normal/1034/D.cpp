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
#define pii pair<int,int>

const int N=3e5+99,inf=1e9+9;

int n,k,p,sum1,sum2,a[N],L[N],R[N];
vector<pii> vec[N];

void pre(){
	set<pair<int,int>> s;
	s.insert({1,0});
	s.insert({inf,0});
	f_(i,n,1){
		if(L[i]==R[i]) continue ;
		pii lst=*prev(s.upper_bound({L[i],N}));
		while(1){
			pii nxt=*s.upper_bound(lst);
			vec[i].pb({lst.S,min(R[i],nxt.F)-max(L[i],lst.F)});
			if(R[i]<=nxt.F) break;
			lst=nxt;
			s.erase(nxt);
		}
		if((*s.lower_bound({L[i],0})).F==L[i]) s.erase(*s.lower_bound({L[i],0}));
		s.insert({L[i],i});
		if((*s.lower_bound({R[i],0})).F!=R[i]) s.insert({R[i],lst.S});
		
	}
}
void add(int x,int val){
	if(x==0) return ;
	a[x]+=val;
	if(x<p){
		sum1+=val;
	}
	sum2+=val*(n+1-max(x,p));
}
pii calc(int x){
	fill(a,a+N,0);
	pair<int,int> res;
	sum1=0,sum2=0;
	p=n+1;
	f_(i,n,1){
		add(i,R[i]-L[i]);
		for(auto p : vec[i]) add(p.F,-p.S);
		while(sum1>=x){
			p--;
			sum2+=sum1;
			sum1-=a[p];
		}
		res.F+=n+1-p;
		res.S+=sum2;
	}
	return res;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>k;
	f(i,1,n+1) cin>>L[i]>>R[i];
	pre();
	int l=0,r=inf;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(calc(mid).F>=k) l=mid;
		else r=mid;
	}
	pii e=calc(r);
	int ans=e.S+(k-e.F)*l;
	cout<<ans;
}