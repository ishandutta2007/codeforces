#include<bits/stdc++.h>
using namespace std;
int i,n,x,y;
vector<int> v[105000];
double res;
void dfs(int x,int fa,double d){
	res+=1/d;
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs(i,x,d+1);
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0,1);
	printf("%.20lf",res);
}