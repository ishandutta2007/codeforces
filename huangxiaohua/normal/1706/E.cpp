#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,fa[200500],t1,res[200500],xx[200500],yy[200500];
vector<tuple<int,int,int> > q[200500];
vector<int> v[200500];
set<pair<int,int> >s;

int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

void hb(int x,int y,int t){
	if(q[x].size()<q[y].size()){
		for(auto [l,r,id]:q[x]){
			auto [l1,r1]=*(--s.upper_bound({l,1e9}));
			if(res[id]==-1&&l>=l1&&r<=r1){
				res[id]=t;
			}
			q[y].push_back({l,r,id});
		}
		swap(q[x],q[y]);
	}
	else{
		for(auto [l,r,id]:q[y]){
			auto [l1,r1]=*(--s.upper_bound({l,1e9}));
			if(res[id]==-1&&l>=l1&&r<=r1){
				res[id]=t;
			}
			q[x].push_back({l,r,id});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>t1;
		s.clear();
		for(i=1;i<=n;i++){
			fa[i]=i;
			q[i].clear();
			v[i]={i};
			s.insert({i,i});
		}
		s.insert({n+1,n+1});s.insert({0,0});
		for(i=1;i<=m;i++)cin>>xx[i]>>yy[i];
		for(i=1;i<=t1;i++){
			cin>>j>>k;
			res[i]=-1;
			if(j==k){
				res[i]=0;continue;
			}
			q[j].push_back({j,k,i});
			q[k].push_back({j,k,i});
		}
		for(j=1;j<=m;j++){
			int x,y;
			x=xx[j];y=yy[j];
			x=find(x);y=find(y);
			if(x==y)continue;
			if(v[x].size()<v[y].size())swap(x,y);
			fa[y]=x;
			for(auto i:v[y]){
				auto it=s.upper_bound({i,1e9});
				auto [l2,r2]=*it;
				auto [l1,r1]=*(--it);
				auto [l0,r0]=*(--it);
				//printf("NMSL%d %d %d %d %d %d %d\n",x,y,i,l1,r1,l2,r2);
				if(l2<=n){
					if(find(r1)==find(l2)){
						s.erase({l1,r1});
						s.erase({l2,r2});
						s.insert({l1,r2});
						r1=r2;
						hb(l1,l2,j);
					}
				}
				
				if(l0!=0){
					
					if(find(r0)==find(l1)){
						s.erase({l0,r0});
						s.erase({l1,r1});
						s.insert({l0,r1});
						hb(l0,l1,j);
					}
				}
				v[x].push_back(i);
			}
			//cout<<"NMSL "<<j<<endl;
			
		}
		for(i=1;i<=t1;i++){
			cout<<res[i]<<' ';
			if(res[i]<0)return i;
		}
		cout<<'\n';
	}
}