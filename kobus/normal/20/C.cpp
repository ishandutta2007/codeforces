//Giovanna Kobus Conrado

#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int,int> > are[112345];

int dis[112345];
int pai[111235];

void dij(){
	for(int i=0;i<112345;i++)dis[i]=-1;
	dis[0]=0;
	set<pair<int,int> > s;
	s.insert(make_pair(0,0));
	while(s.size()>0){
		pair<int,int> curr=*s.begin();
		s.erase(s.begin());
		int u=curr.second;
		int diss=curr.first;
		if(diss!=dis[u])continue;
		for(auto x:are[u]){
			if(dis[x.second]==-1 || dis[x.second]>dis[u]+x.first){
				pai[x.second]=u;
				dis[x.second]=dis[u]+x.first;
				s.insert(make_pair(dis[x.second],x.second));
			}
		}
	}
}

int32_t main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		int c;
		cin>>c;
		are[a].push_back(make_pair(c,b));
		are[b].push_back(make_pair(c,a));
	}
	//cout<<"AAA"<<endl;
	dij();
	if(dis[n-1]==-1){
		cout<<-1<<endl;
		return 0;
	}
	vector<int> ans;
	int curr=n-1;
	ans.push_back(curr);
	while(curr!=0){
		curr=pai[curr];
		ans.push_back(curr);
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans)cout<<x+1<<" ";
	cout<<endl;
}