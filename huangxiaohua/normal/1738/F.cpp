#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t,it,d[1005],fa[1005],vis[1005];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
map<int,int> mp;

int main(){
	ios::sync_with_stdio(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		vector<pair<int,int> >v;
		it=0;
		mp.clear();
		for(i=1;i<=n;i++){
			fa[i]=i; vis[i]=0;
			cin>>d[i];
			v.push_back({-d[i],i});
		}
		
		sort(v.begin(),v.end());
		for(auto [w,i]:v){
			if(vis[i])continue;
			while(d[i]--){
				if(!d[i])break;
				cout<<"? "<<i<<endl;
				cin>>k;
				int x=find(i),y=find(k);
				fa[x]=y;
				if(vis[k])break;
				vis[k]=1;
			}
			vis[i]=1;
		}
		cout<<"! ";
		for(i=1;i<=n;i++){
			if(!mp[find(i)])mp[find(i)]=++it;
			cout<<mp[find(i)]<<' ';
		}
		cout<<endl;
	}
		
}