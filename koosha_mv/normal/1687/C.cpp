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

int n,m,t,a[N],b[N],l[N],r[N],mark[N];
vector<int> vec[N];
queue<pair<int,int>> q;

void del(int x){
	a[x]=0;
	for(auto id : vec[x]) if(++mark[id]==2) q.push({l[id],r[id]});
}
void Main(){
	set<int> s;
	cin>>n>>m;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1) cin>>b[i],a[i]-=b[i];
	f(i,1,n+1) a[i]+=a[i-1];
	f(i,0,n+1) if(a[i]!=0) s.insert(i);
	f(i,0,m){
		cin>>l[i]>>r[i]; l[i]--;
		vec[l[i]].pb(i);
		vec[r[i]].pb(i);
		mark[i]=(a[l[i]]==0)+(a[r[i]]==0);
		if(mark[i]==2) q.push({l[i],r[i]});
	}
	while(q.size()){
		int l=q.front().F,r=q.front().S;
		//erorp(mp(l,r));
		q.pop();
		while(s.size() && l<=*s.rbegin() && *s.lower_bound(l)<=r){
			del(*s.lower_bound(l));
			s.erase(*s.lower_bound(l));
		}
	}
	if(s.size()==0) cout<<"YES"<<'\n';
	else cout<<"NO"<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		f(i,0,n+1) vec[i].clear();
	}
}
/*
1
5 2
1 5 4 2 3
3 2 5 4 1
1 3
2 5
*/