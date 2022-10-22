#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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
#define sz(x) ((ll) x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99;

int n,m,t,a[N],sum[N];
vector<int> v[N];
string ans[N];

void solve(int l,int r,set<pair<int,int> > s){
	/*cout<<l<<" "<<r<<" : ";
	for(auto p : s){
		cout<<p.F<<endl;
	}*/
	if(l+1==r){
		f(i,0,v[l].size()){
			int sz=v[l].size()-1,x=(sum[l]-v[l][i]+sz-1)/sz;
			if(x<=(*s.rbegin()).F){
				ans[l][i]='1';
			}
		}
		return ;
	}
	int mid=(l+r)/2,mv=1;
	set<pair<int,int> > copy=s;
	f(i,mid,r){
		int sz=v[i].size(),x=(sum[i]+sz-1)/sz;
		if(s.lower_bound({x,0})==s.end()){
			mv=0;
			break;
		}
		s.erase(s.lower_bound({x,0}));
	}
	if(mv==1){
		solve(l,mid,s);
	}
	mv=1;
	s=copy;
	f(i,l,mid){
		int sz=v[i].size(),x=(sum[i]+sz-1)/sz;
		if(s.lower_bound({x,0})==s.end()){
			mv=0;
			break;
		}
		s.erase(s.lower_bound({x,0}));
	}
	if(mv==1){
		solve(mid,r,s);
	}
}
void Main(){
	set<pair<int,int> > s;
	cin>>n>>m;
	f(i,0,n) cin>>a[i];
	sort(a,a+n,greater<int>()); n=m;
	f(i,0,n){
		s.insert({a[i],i});
	}
	f(i,0,n){
		int k;
		cin>>k;
		ans[i]="";
		sum[i]=0;
		v[i].clear();
		f(j,0,k){
			int x;
			cin>>x;
			v[i].pb(x);
			sum[i]+=x;
			ans[i]+='0';
		}
	}
	solve(0,n,s);
	f(i,0,n){
		cout<<ans[i];
	}
	cout<<endl;
}

main(){
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
1 1
30
3
25 16 37

*/