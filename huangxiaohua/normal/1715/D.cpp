#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res[100500],li[100500];
vector<pair<int,int> >v[100500];

int main(){
	ios::sync_with_stdio(0);
	for(i=1;i<=100000;i++){
		li[i]=(1<<30)-1;
	}
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		li[x]&=w;
		li[y]&=w;
		if(x==y){
			res[x]=w;continue;
		}
		if(x>y)swap(x,y);
		v[x].push_back({y,w});
	}
	for(i=1;i<=n;i++){
		int t1,t2,t3;
		for(auto [j,w]:v[i]){
			t1=(w&li[j]);
			t1^=w;
			res[i]|=t1;
		}
		for(auto [j,w]:v[i]){
			t1=(w&res[i]);
			t1^=w;
			res[j]|=t1;
		}
	}
	for(i=1;i<=n;i++){
		cout<<res[i]<<' ';
	}
}