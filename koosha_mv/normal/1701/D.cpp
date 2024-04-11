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

const int N=5e6+99;

int n,t,a[N],ans[N];
vector<pair<int,int>> ad[N];

int findl(int x,int y){
	if(y==0) return x+1;
	int l=0,r=N;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(x/mid>y) l=mid;
		else r=mid;
	}
	return r;
}
int findr(int x,int y){
	if(y==0) return n;
	int l=0,r=N;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(x/mid<y) r=mid;
		else l=mid;
	}
	return l;
}
void Main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		int l=findl(i,a[i]),r=findr(i,a[i]);
		ad[max(1ll,l)].pb({r,i});
	}
	set<pair<int,int>> s;
	f(i,1,n+1){
		for(auto x : ad[i]){
			s.insert(x);
		}
		pair<int,int> p=*s.begin();
		s.erase(p);
		ans[p.S]=i;
	}
	f(i,1,n+1) cout<<ans[i]<<" "; cout<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		f(i,0,n+1) ad[i].clear();
	}
}