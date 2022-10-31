#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,fa[200500],vis[200500],vis2[200500];
ll a[200500],b[200500],sa,sb,p[200500];
vector<tuple<int,int,int> > v[200500];
vector<int> v1;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	sa=sb=0;
    	for(i=1;i<=n;i++){
    		vis[i]=0;
    		v[i].clear();
    		fa[i]=i;
		}
		fa[n+1]=n+1;
    	for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++)cin>>b[i];
		for(i=1;i<=n;i++){
			sa+=a[i];sb+=b[i];
			p[i]=p[i-1]+a[i]-b[i];
		}
		queue<pair<int,int> >q;
		for(i=1;i<=m;i++){
			vis2[i]=0;
			cin>>j>>k;
			v[j].push_back({j,k,i});
			v[k].push_back({j,k,i});
			if(p[j-1]==0&&p[k]==0){
				q.push({j,k});
				vis2[i]=1;
			}
		}
		if(sa!=sb){
			cout<<"NO\n";continue;
		}
		while(!q.empty()){
			auto [l,r]=q.front();q.pop();
			//printf("NMSL%d %d\n",l,r);
			
			i=l;if(vis[i])i=find(i)+1;
			v1.clear();
			for(;i<=r;i=find(i)+1){
				vis[i]=1;
				v1.push_back(i);
				for(auto [x,y,id]:v[i]){
					if(vis2[id])continue;
					//printf("nmsl%d %d %d\n",x,y,i);
					if( (vis[x]||p[x-1]==0) && (vis[y]||p[y]==0) ){
						vis2[id]=1;
						q.push({x,y});
					}
				}
			}
			for(auto i:v1){
				fa[i]=find(r);
			}
		}
		for(i=1;i<=n;i++){
			if(!vis[i]&&a[i]!=b[i]){
				cout<<"NO\n";goto aaa;
			}
		}
		cout<<"YES\n";
		aaa:;
	}
}