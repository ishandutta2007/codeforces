#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,t,m,it,cur,vis[2005000],rnk[2005000],it2;
ll res[2005000];
vector<pair<int,int> > v[2000500];
void Add(int j,int k,string s){
	cur=j;
	while(s.size()>1){
		t=(*--s.end());s.pop_back();
		v[cur].push_back({t-'0',++it});
		cur=it;
	}
	v[cur].push_back({s[0]-'0',k});
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	it=n;
	for(i=1;i<=m;i++){
		string s=to_string(i);reverse(s.begin(),s.end());
		cin>>j>>k;
		Add(j,k,s);Add(k,j,s);
	}
	for(i=1;i<=n;i++){
		if(!v[i].empty())sort(v[i].begin(),v[i].end());
	}
	vector<int> q={1},q2;
	vis[1]=1;
	vector<tuple<int,int,int,int> >v2;
	while(!q.empty()){
		v2.clear();
		for(auto i:q){
			for(auto [y,x]:v[i]){
				if(vis[x])continue;
				v2.push_back({rnk[i],y,x,(res[i]*10+y)%M});
			}
		}
		if(v2.empty())break;
		sort(v2.begin(),v2.end());
		pair<int,int> lst={-1,-1};
		for(auto [rk1,rk2,id,wt]:v2){
			if(vis[id])continue;
			q2.push_back(id);
			vis[id]=1;
			if(make_pair(rk1,rk2)!=lst){
				it2++;
			}
			rnk[id]=it2;
			res[id]=wt;
			lst={rk1,rk2};
		}
		swap(q,q2);q2.clear();
	}
	for(i=2;i<=n;i++)cout<<res[i]<<'\n';
}