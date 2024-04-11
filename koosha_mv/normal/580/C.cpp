#include<iostream>
#include<vector>
using namespace std;
int ans=0,mark[100009],v[100009],x,y,n,m;
vector<int> e[100009];
int dfs(int x,int c){
	mark[x]=1;
	if(v[x]==0) c=0;
	c+=v[x];
	if(c>m) return 0;
	//cout<<x<<" "<<c<<endl;
	int t=0;
	for(int i=0;i<e[x].size();i++){
		if(mark[e[x][i]]==0)
			dfs(e[x][i],c),t=1;
	}
	//cout<<x<<" "<<t<<endl;
	if(t==0) ans++;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n-1;i++){
		cin>>x>>y;x--;y--;
		e[x].push_back(y);
		e[y].push_back(x);}
	dfs(0,0);
	cout<<ans;
}