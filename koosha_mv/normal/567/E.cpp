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

const int N=1e6+99,inf=1e14;

int n,m,s,t,a[N],b[N],len[N],Max[N];
vector<pair<int,int>> g[N];
map<int,int> cnt;

vector<int> diji(int src){
	vector<int> dist(n);
	set<pair<int,int>> s;
	f(i,0,n){
		dist[i]=(i==src ? 0 : inf);
		s.insert({dist[i],i});
	}
	while(s.size()){
		int u=(*s.begin()).S;
		s.erase(*s.begin());
		for(auto p : g[u]){
			int v=p.F,d=p.S;
			if(dist[u]+d<dist[v]){
				s.erase({dist[v],v});
				dist[v]=dist[u]+d;
				s.insert({dist[v],v});
			}
		}
	}
	return dist;
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m>>s>>t; s--,t--;
	f(i,0,m){
		cin>>a[i]>>b[i]>>len[i];
		a[i]--,b[i]--;
		g[a[i]].pb({b[i],len[i]});
	}
	vector<int> dist1,dist2;
	vector<pair<int,int>> vec;
	vec.pb({0,0});
	dist1=diji(s);
	f(i,0,n) g[i].clear();
	f(i,0,m) g[b[i]].pb({a[i],len[i]});
	dist2=diji(t);
	f(i,0,m){
		if(dist1[a[i]]+dist2[b[i]]+len[i]==dist1[t]){
			cnt[dist1[a[i]]]++;
			vec.pb({dist1[a[i]],dist1[b[i]]});
		}
	}
	sort(all(vec));
	f(i,1,vec.size()) Max[i]=max(Max[i-1],vec[i].S);
	f(i,0,m){
		if(dist1[a[i]]+dist2[b[i]]+len[i]==dist1[t]){
			int p=lower_bound(all(vec),mp(dist1[a[i]],dist1[b[i]]))-vec.begin()-1;
			if(Max[p]<=dist1[a[i]] && cnt[dist1[a[i]]]<2){
				cout<<"YES"<<'\n';
				continue ;
			}
		}
		if(dist1[a[i]]+dist2[b[i]]+1<dist1[t]){
			cout<<"CAN"<<" "<<dist1[a[i]]+dist2[b[i]]+len[i]-dist1[t]+1<<'\n';
			continue ;	
		}
		cout<<"NO"<<'\n';
		
	}
}