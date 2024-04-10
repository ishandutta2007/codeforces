#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,fa[1005000],res;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

int main(void){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=n;
		priority_queue<pair<int,int> > q,q2;
		vector<tuple<int,int,int,int> >v,v2;
		for(i=1;i<=n;i++){
			fa[i]=i;
			int ty;
			cin>>ty>>j>>k;
			v.push_back({j,k,-ty,i});
			v2.push_back({j,k,ty,i});
		}
		sort(v.begin(),v.end());
		sort(v2.begin(),v2.end());
		for(auto [l,r,ty,id]:v){
			while(!q.empty()){
				auto [x,y]=q.top();x=-x;
				if(x<l)q.pop();
				else break;
			}
			if(!ty){
				while(!q.empty()){
					auto [x,y]=q.top();x=-x;
					if(find(y)!=find(id)){
						res--;fa[find(y)]=find(id);
					}
					if(q.size()>1)q.pop();
					else break;
				}
			}
			else q.push({-r,id});
		}
		for(auto [l,r,ty,id]:v2){
			while(!q2.empty()){
				auto [x,y]=q2.top();x=-x;
				if(x<l)q2.pop();
				else break;
			}
			if(ty){
				while(!q2.empty()){
					auto [x,y]=q2.top();x=-x;
					if(find(y)!=find(id)){
						res--;fa[find(y)]=find(id);
					}
					if(q2.size()>1)q2.pop();
					else break;
				}
			}
			else q2.push({-r,id});
		}
		cout<<res<<'\n';
	}
}