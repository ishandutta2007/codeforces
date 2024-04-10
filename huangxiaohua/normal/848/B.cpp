#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,rx,ry,a[500500],s[500500],it1,it2;
pair<int,int> res[500500];

map<int,vector<tuple<int,int,int> > >mp;
vector<pair<int,int> >sx,sy;

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>rx>>ry;
	for(t=1;t<=n;t++){
		cin>>i>>j>>k;
		mp[j-k].push_back({t,i,j});
	}
	for(auto [i,v]:mp){
		sx.clear();
		sy.clear();
		
		for(auto [id,ty,pos]:v){
			if(ty==1)sx.push_back({pos,id});
			else sy.push_back({pos,id});
		}
		
		if(sx.size())sort(sx.begin(),sx.end());
		if(sy.size())sort(sy.begin(),sy.end());
		
		it1=it2=0;
		for(auto [i,j]:sx)s[++it1]=i;
		reverse(sy.begin(),sy.end());
		for(auto [i,j]:sy){
			it2++;if(it2>it1)break;
			res[j]={s[it2],ry};
		}
		reverse(sy.begin(),sy.end());
		for(auto [i,j]:sx){
			it2++;if(it2>it1)break;
			res[j]={s[it2],ry};
		}
		
		it1=it2=0;
		for(auto [i,j]:sy)s[++it1]=i;
		reverse(sx.begin(),sx.end());
		for(auto [i,j]:sx){
			it2++;if(it2>it1)break;
			res[j]={rx,s[it2]};
		}
		reverse(sx.begin(),sx.end());
		for(auto [i,j]:sy){
			it2++;if(it2>it1)break;
			res[j]={rx,s[it2]};
		}
	}
	for(i=1;i<=n;i++){
		auto [x,y]=res[i];
		cout<<x<<' '<<y<<'\n';
	}
}