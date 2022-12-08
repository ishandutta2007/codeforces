#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2
#define int long long

int adj[412345];
vector<int> are[412345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			a--;b--;
			are[a].pb(b);
			are[b].pb(a);
		}
		set<int> nxt;
		set<int> lea;
		set<int> rem;
		int com=0;
		for(int i=0;i<n;i++){
			adj[i]=are[i].size();
			if(are[i].size()<=1)lea.insert(i);
		}
		//for(int u:lea)cout<<u<<" ";
		//                           cout<<endl;
		for(int i=0;i<k;i++){
			for(int u:lea){
				for(int v:are[u]){
					adj[v]--;
					if(adj[v]<=1 && lea.find(v)==lea.end() && rem.find(v)==rem.end())
						nxt.insert(v);
				}
			}
			for(int u:lea)rem.insert(u);
			lea=nxt;
			nxt.clear();
			if(lea.size()==0)break;
		}
		for(int i=0;i<n;i++)are[i].clear();
		cout<<n-rem.size()<<endl;
	}
}