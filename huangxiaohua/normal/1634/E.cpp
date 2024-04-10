#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sz[200500],vis[200500],tot,rt;
vector<int> res[200500];
map<int,int> mp,mp3;
map<int,set<pair<int,int> > >mp2;
map<int,set<pair<int,int> > >mp4;
set<pair<int,int> > *s;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>m;sz[i]=m;
		vector<int> v0(m+5);
		res[i]=v0;
		mp.clear();
		for(j=1;j<=m;j++){
			cin>>k;
			mp3[k]^=1;
			if(mp[k]){
				res[i][j]=1;
				mp[k]=0;
			}
			else mp[k]=j;
		}
		for(auto [x,y]:mp){
			if(y){
				mp2[x].insert({i,y});
				mp4[i].insert({x,y});
				tot++;
			}
		}
	}
	for(auto &[x,y]:mp3){
		if(y&1){cout<<"NO";return 0;}
	}
	for(i=1;i<=n;i++){
		while(1){
			if(mp4[i].empty())break;
			k=0;int cur=i;
			while(1){
				s=&mp4[cur];
				auto [x,y]=*s->begin();
				res[cur][y]=k;
				k^=1;
				mp4[cur].erase({x,y});
				mp2[x].erase({cur,y});
				s=&mp2[x];
				auto [z,y2]=*s->begin();
				cur=z;
				res[cur][y2]=k;
				mp4[cur].erase({x,y2});
				mp2[x].erase({cur,y2});
				if(k==1&&cur==i)break;
				k^=1;
			}
		}
	}
	cout<<"YES\n";
	for(i=1;i<=n;i++){
		for(j=1;j<=sz[i];j++){
			cout<<"LR"[res[i][j]];
		}cout<<'\n';
	}
}