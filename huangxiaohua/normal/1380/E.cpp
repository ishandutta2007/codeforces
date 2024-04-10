#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,fa[200500],id[200500],res;
vector<int> v[200500];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

void hb(int x,int y){
	if(v[x].size()<v[y].size()){
		for(auto i:v[x]){
			v[y].push_back(i);
			if(find(id[i-1])==y)res--;
			if(find(id[i+1])==y)res--;
		}
		swap(v[x],v[y]);v[y].clear();
	}
	else{
		for(auto i:v[y]){
			v[x].push_back(i);
			if(find(id[i-1])==x)res--;
			if(find(id[i+1])==x)res--;
		}
		v[y].clear();
	}
	fa[y]=x;
}

int main(){
	ios::sync_with_stdio(0);
	for(i=1;i<=200000;i++)fa[i]=i;
	cin>>n>>m;res=n-1;
	for(i=1;i<=n;i++){
		cin>>k;
		v[k].push_back(i);
		id[i]=k;
	}
	for(i=1;i<n;i++){
		if(id[i]==id[i+1])res--;
	}
	cout<<res<<'\n';
	for(i=1;i<m;i++){
		cin>>j>>k;
		hb(j,k);
		cout<<res<<'\n';
	}
}