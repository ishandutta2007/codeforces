#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l[2005000],r[2005000],res[2005000];
vector<pair<int,int> >v[2005000];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)v[i].clear();
		for(i=1;i<=n;i++){
			cin>>k;
			if(!k)r[i]=n;
			else r[i]=i/k;
			l[i]=i/(k+1)+1;
			v[l[i]].push_back({i,r[i]});
		}
		priority_queue<pair<int,int> >q;
		for(i=1;i<=n;i++){
			for(auto [x,y]:v[i]){
				q.push({-y,x});
			}
			auto [x,y]=q.top();q.pop();
			res[y]=i;
		}
		for(i=1;i<=n;i++){
			assert(res[i]>=l[i]&&res[i]<=r[i]);
			cout<<res[i]<<' ';
		}
		cout<<'\n';
	}
}