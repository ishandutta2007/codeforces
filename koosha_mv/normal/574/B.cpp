#include<iostream>
using namespace std;
int x,y,n,m,deg[4009],mindeg=100009;
bool graph[4009][4009];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		graph[x][y]=1;
		graph[y][x]=1;
		deg[x]++;
		deg[y]++;}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(graph[i][j]==1){
				for(int k=j+1;k<=n;k++){
					//cout<<i<<" "<<j<<" "<<k<<endl;
					if(graph[i][k]==1 && graph[j][k]==1)mindeg=min(mindeg,deg[i]+deg[j]+deg[k]);
}}}}
	if(mindeg==100009)
		cout<<-1;
	else
		cout<<mindeg-6;
}