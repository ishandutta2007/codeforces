#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

const int N=1010;
vector<int>g[N][2][2];
int dist[N][N];
pair<int,int>nxt[N][N];
vector<pair<int,int>>res;
int n,m;

int get(int u,int v){
	if(~dist[u][v])return dist[u][v];
	int dst=0;
	res.push_back({u,v});
	if(2*((int)res.size()-1)>=m)return -1;
	for(int i=0;i<2;++i){
		for(auto u2:g[u][i][1]){
			for(auto v2:g[v][i][0]){
				int ds=get(u2,v2);
				if(2*((int)res.size()-1)>=m)return -1;
				if(ds+1>dst){
					dst=ds+1;
					nxt[u][v]={u2,v2};
				}
			}
		}
	}
	res.pop_back();
	return dist[u][v]=dst;
}

void build(int u,int v){
	res.push_back({u,v});
	while(2*res.size()<m){
		tie(u,v)=nxt[u][v];
		res.push_back({u,v});
	}
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>m;
		res.clear();
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dist[i][j]=-1;
		for(int i=0;i<n;++i){
			g[i][0][0].clear();
			g[i][0][1].clear();
			g[i][1][0].clear();
			g[i][1][1].clear();
		}
		for(int i=0;i<n;++i){
			string s;cin>>s;
			for(int j=0;j<n;++j)if(s[j]!='*'){
				g[i][s[j]-'a'][0].push_back(j);
				g[j][s[j]-'a'][1].push_back(i);
			}
		}
		if(m%2){
			cout<<"YES\n";
			for(int i=0;i<m+1;++i)cout<<(i%2)+1<<" ";cout<<endl;
			continue;
		}
		bool pos=false;
		for(int i=0;i<n&&!pos;++i){
			int dst=get(i,i);
			if(2*((int)res.size()-1)>=m){
				pos=true;
				break;
			}
			if(2*dst>=m){
				build(i,i);
				pos=true;
				break;
			}
		}
		if(pos){
			cout<<"YES\n";
			int rr=res.size();
			for(int i=rr-1;i>=0;--i)cout<<res[i].first+1<<" ";
			for(int i=1;i<rr;++i)cout<<res[i].second+1<<" ";
			cout<<endl;
		}
		else cout<<"NO\n";
	}
}