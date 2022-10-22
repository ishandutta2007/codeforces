#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e3+9;
int n;
int d[M],id[M],f[M],vis[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
void work(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>d[i];
		id[i]=f[i]=i;
		vis[i]=0;
	}
	sort(id+1,id+n+1,[&](const int&l,const int&r){return d[l]>d[r];});
	for(int i=1;i<=n;++i){
		int u=id[i];
		if(!vis[u]){
			vis[u]=1;
			for(int j=1;j<=d[u];++j){
				cout<<"? "<<u<<"\n";
				int v;
				cin>>v;
				merge(u,v);
				if(vis[v])break;
				vis[v]=1;
			}
		}
	}
	cout<<"! ";
	for(int i=1;i<=n;++i){
		cout<<find(i)<<" \n"[i==n];
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}