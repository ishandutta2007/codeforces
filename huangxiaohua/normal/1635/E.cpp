#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[200500],vis[200500],it,sb=11451419,rnk[200500],in[200500];
vector<int> v[200500],v1[200500],v2[200500],q,v0,v3[200500];
//vector<tuple<int,int,int> >q;
pair<string,int> res[200500];

bool cmp(int x,int y){
	return rnk[x]<rnk[y];
}

void dfs(int x){
	//printf("a%d %d\n",x,f[x]);
	vis[x]=1;
	q.push_back(x);
	for(auto i:v[x]){
		if(f[i]==-1){
			f[i]=(f[x]^1);
		}
		else{
			if(f[i]!=(f[x]^1)){
				cout<<"NO";exit(0);
			}
		}
		if(vis[i])continue;
		dfs(i);
	}
}

int main(){
	memset(f,-1,sizeof(f));
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int ty;
		cin>>ty>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
		if(ty==1){
			v1[j].push_back(k);
			v1[k].push_back(j);
		}
		else{
			v2[j].push_back(k);
			v2[k].push_back(j);
		}
		//q.push_back({ty,j,k});
	}
	for(i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		f[i]=0;
		q.clear();
		dfs(i);
		if(q.size()==1){
			res[i]={"R",sb};
			sb--;continue;
		}
		for(auto i:q){
			if(f[i]==0){
				int mx=0;
				for(auto j:v1[i]){
					v3[j].push_back(i);
					in[i]++;
				}
				for(auto j:v2[i]){
					v3[i].push_back(j);
					in[j]++;
				}
			}
		}
		
		queue<int> qu;
		for(auto i:q){
			if(!in[i])qu.push(i);
		}
		while(!qu.empty()){
			auto k=qu.front();qu.pop();
			for(auto i:v3[k]){
				if(!in[i])exit(1);
				in[i]--;
				rnk[i]=max(rnk[i],rnk[k]+1);
				if(!in[i])qu.push(i);
			}
		}
		for(auto i:q){
			//printf("NMSL%d %d\n",i,rnk[i]);
			if(f[i])continue;
			for(auto j:v1[i]){
				if(rnk[j]>=rnk[i]){
					cout<<"NO";return 0;
				}
			}
			for(auto j:v2[i]){
				if(rnk[j]<=rnk[i]){
					cout<<"NO";return 0;
				}
			}
		}
		sort(q.begin(),q.end(),cmp);
		for(auto i:q){
			if(f[i]==0){
				res[i]={"R",++it};
			}
			else{
				res[i]={"L",++it};
			}
		}
	}
	cout<<"YES\n";
	for(i=1;i<=n;i++){
		auto [x,y]=res[i];
		cout<<x<<' '<<y<<'\n';
	}
}