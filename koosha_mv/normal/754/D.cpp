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
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll
#define pii pair<int,int>

const int N=1e6+99,inf=2e9+99;

int n,k,a[N],l[N],r[N];
vector<int> v,ans;

bool check(int x,int t=0){
	priority_queue<pii,vector<pii>,greater<pii>> s;
	f(i,0,v.size()){
		s.push({r[v[i]],v[i]});
		while(s.size() && s.top().F<l[v[i]]+x-1) s.pop();
		if(s.size()>=k){
			if(t==1){
				while(s.size()){
					ans.pb(s.top().S);
					s.pop();
				}
			}
			return 1;
		}
	}
	return 0;
}
bool cmp(int i,int j){
	return mp(l[i],r[i])<mp(l[j],r[j]);
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>k;
	f(i,0,n){
		cin>>l[i]>>r[i];
		v.pb(i);
	}
	sort(all(v),cmp);
	
	int l=0,r=inf;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	check(l,1);
	cout<<l<<endl;
	if(l==0){
		f(i,0,k) cout<<i+1<<" ";
		exit(0);
	}
	f(i,0,k) cout<<ans[i]+1<<" ";
}