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

const int N=1e6+99;

int n,t,q,a[N],b[N],c[N],mv[N],ps[N],L[N],R[N];
vector<int> vec[N];

void Main(){
	ll ans=0;
	cin>>n;
	f(i,1,n+1){
		L[i]=N;
		cin>>a[i];
		minm(a[i],i);
		b[i]=n+1;
	}
	vector<int> now;
	now.pb(n+1);
	now.pb(n+1);
	f_(i,n,1){
		vec[i-a[i]].pb(i);
		for(auto x : vec[i]){
			now.pb(x);
			sort(all(now));
			now.pop_back();
		}
		b[i]=now[0];
		c[i]=now[1];
		ans+=b[i]-i;
		minm(L[b[i]],i);
		maxm(R[b[i]],i);
	}
	//dbga(b,1,n+1);
	f(i,1,n+1) ps[i]=ps[i-1]+b[i],mv[i]=mv[i-1]+c[i];
	cin>>q;
	while(q--){
		int p,x,res=ans;
		cin>>p>>x; minm(x,p);
		if(x<=a[p]){
			int l=p-a[p],r=p-x+1;
			while(l+1<r){
				int mid=(l+r)>>1;
				if(b[mid]<p) l=mid;
				else r=mid;
			}
			r=p-x;
			res+=p*(r-l)-(ps[r]-ps[l]);
			cout<<res<<'\n';
		}
		else{
			int l=p-x+1,r=p-a[p];
			maxm(l,L[p]);
			minm(r,R[p]);
			if(l<=r){
				res-=(r-l+1)*p;
				res+=mv[r]-mv[l-1];
			}
			cout<<res<<'\n';
		}
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	t=1;
	while(t--){
		Main();
	}
}