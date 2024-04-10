#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[100500],mn;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		priority_queue<pair<int,int> >q;
		for(i=1;i<=n;i++){
			cin>>a[i];
			q.push({a[i],a[i]});
		}
		mn=a[1];
		res=a[n]-a[1];
		while(!q.empty()){
			auto [x,y]=q.top();q.pop();
			res=min(res,x-mn);
			if(!res)break;
			k=y/x+1;
			if(k>m)break;
			mn=min(mn,y/k);
			q.push({y/k,y});
		}
		cout<<res<<'\n';
	}
}