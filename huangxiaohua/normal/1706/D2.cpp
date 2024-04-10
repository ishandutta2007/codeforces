#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[100500],mn,x,y;
vector<int>q[100500];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=100000;i++){
			q[i].clear();a[i]=0;
		}
		mn=1e9;
		for(i=1;i<=n;i++){
			cin>>k;
			mn=min(mn,k);
			q[k].push_back(k);
		}
		res=k-mn;
		for(i=100000;i>=1;i--){
			res=min(res,i-mn);
			if(!res)break;
			for(auto j:q[i]){
				x=i;y=j;
				k=y/x+1;
				if(k>m)goto aaa;
				mn=min(mn,y/k);
				q[y/k].push_back(y);
			}
			vector<int> NMSL;
			swap(q[i],NMSL);
		}
		aaa:;
		cout<<res<<'\n';
	}
}