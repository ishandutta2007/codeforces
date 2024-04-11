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

const int N=3e5+99;

int n,m,t,a[N],mark[N];
vector<int> vec[N];

int find(int x,int y){
	int l=0,r=vec[x].size();
	while(l+1<r){
		int mid=(l+r)>>1;
		if(vec[x][mid]>=y){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	return l;
}
void Main(){
	map<int,int> cnt;
	vector<int> v;
	map<int,vector<pair<int,int> > > g;
	ll ans=0;
	
	cin>>n>>m;
	f(i,1,n+1){
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(auto p : cnt){
		if(!mark[p.S]){
			v.pb(p.S);
			mark[p.S]=1;
		}
	}
	sort(all(v));
	for(auto p : cnt){
		int e=lower_bound(all(v),p.S)-v.begin();
		vec[e].pb(p.F);
	}
	f(i,0,v.size()){
		sort(all(vec[i]),greater<int> ());
		//cout<<v[i]<<" : "; f(j,0,vec[i].size()) cout<<vec[i][j]<<" "; cout<<endl;
	}
	f(i,0,m){
		int x,y,px,py,e1,e2;
		cin>>x>>y;
		e1=lower_bound(all(v),cnt[x])-v.begin();
		e2=lower_bound(all(v),cnt[y])-v.begin();
		px=find(e1,x);
		py=find(e2,y);
		/*eror(e1);
		eror(e2);
		eror(px);
		eror(py);*/
		g[x].pb({e2,py});
		g[y].pb({e1,px});
	}
	for(auto e : cnt){
		int x=e.F,p=0;
		vector<pair<int,int> > adj=g[x];
		sort(all(adj));
		/*erorp(e);
		f(i,0,adj.size()){
			cout<<adj[i].F<<" "<<adj[i].S<<endl;
		}*/
		f(i,0,v.size()){
			f(j,0,vec[i].size()){
				while(p<adj.size() && adj[p]<mp(i,j)){
					p++;
				}
				if(vec[i][j]!=x && (p==adj.size() || adj[p]!=mp(i,j))){
					maxm(ans,(e.F+vec[i][j])*(e.S+v[i]));
					//cout<<ans<<" "<<i<<" "<<j<<" "<<e.F<<" "<<vec[i][j]<<endl;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	f(i,0,n+1) mark[i]=0,vec[i].clear();
}
/*
1
7 4
1 2 2 3 1 5 1
1 5
3 5
1 3
2 5
*/
main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		Main();
	}
}