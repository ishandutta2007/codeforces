#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,in[1050],tot,vis[1050],vis2[1050],g[1050];
int f[1050],res;
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
vector<int> v[1050];

void fuck(){
	int i,j,k;
	res++;
	for(i=1;i<=n;i++)g[i]=0;
	for(i=1;i<=n;i++){
		if(!f[i]||vis[i])continue;
		f[i]--;
		for(auto j:v[i]){
			g[j]++;
		}
	}
	for(i=1;i<=n;i++)f[i]+=g[i];
	
	//cout<<"nmsl "<<res<<endl;for(i=1;i<=n;i++){cout<<i<<' '<<f[i]<<' '<<vis[i]<<endl;}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		tot=n;
		for(i=1;i<=n;i++){
			cin>>f[i];
			v[i].clear();
			vis[i]=vis2[i]=0;
		}
		for(i=1;i<=m;i++){
			cin>>j>>k;
			v[j].push_back(k);in[k]++;
		}
		res=0;
		while(1){
			aaa:;
			if(!tot){
				break;
			}
			for(i=1;i<=n;i++){
				if(in[i]||vis[i])continue;
				if(!f[i]){
					tot--;vis[i]=vis2[i]=1;
					for(auto j:v[i]){
						in[j]--;
					}
					goto aaa;
				}
			}
			for(i=1;i<=n;i++){
				if(vis[i])continue;
				if(!f[i]){
					fuck();goto aaa;
				}
			}
			break;
		}
		//if(!tot){cout<<res<<'\n';continue;}
		set<int> s;
		for(i=1;i<=n;i++){
			if(vis[i])continue;
			if(!in[i])s.insert(i);
		}
		f[0]=2e9;
		while(!s.empty()){
			int mn=0;
			for(auto i:s){
				if(f[i]<=f[mn]){
					mn=i;
				}
			}
			s.erase(mn);k=f[mn];
			res=su(res,k);
			for(i=1;i<=n;i++){
				if(vis2[i])continue;
				f[i]=su(f[i],M-k);
				for(auto j:v[i]){
					f[j]=su(f[j],k);
				}
			}
			for(auto i:v[mn]){
				in[i]--;
				if(!in[i]){
					vis[i]=1;
					s.insert(i);
				}
			}
			//cout<<"NMSL "<<res<<endl;for(i=1;i<=n;i++){cout<<i<<' '<<k<<' '<<f[i]<<' '<<vis2[i]<<endl;}
			vis2[mn]=1; 
		}
		cout<<res<<'\n';
	}
}