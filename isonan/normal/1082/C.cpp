#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> vec[100010];
int n,m,s,r,ans[100010],fin;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s>>r;
		vec[s].push_back(r);
	}
	for(int i=1;i<=m;i++)std::sort(vec[i].begin(),vec[i].end());
	for(int i=1;i<=m;i++)
		for(int j=vec[i].size()-1;j>=0;j--){
			if(j!=vec[i].size()-1)vec[i][j]+=vec[i][j+1];
			if(vec[i][j]>0)ans[vec[i].size()-j]+=vec[i][j];//,printf("%d %d %d\n",i,j+1,vec[i][j]);
			else break;
		}
	for(int i=1;i<=n;i++)fin=max(fin,ans[i]);
	cout<<fin;
}