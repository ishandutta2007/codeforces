#include<iostream>
#include<vector>
using namespace std;
int s=0,v[300009],mark[300009],x,y,t1,t2,e1=1e6;
vector<int> e[300009];
int dfs(int x){
	//cout<<"X:"<<x+1<<" "<<endl;
	int d1=0,d2=0,d;
	mark[x]=1;
	for(int i=0;i<e[x].size();i++){
		if(mark[e[x][i]]==0){
			d1+=dfs(e[x][i]);
		}
	}
	d1++;
	//cout<<"D:"<<d1<<endl;
	if(d1%2==0)
		s++;
	return d1;
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		e[x-1].push_back(y-1);
		e[y-1].push_back(x-1);
	}
	if(n%2==1){cout<<-1;return 0;}
	dfs(0);s--;
	cout<<s;
}