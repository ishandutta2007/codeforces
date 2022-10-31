#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,vis[500500],it;
vector<int> v;

int main(){
	scanf("%d%d",&n,&m);
	n=(1<<n);vis[m]=1;
	for(i=1;i<n;i++){
		if(vis[i]){continue;}
		v.push_back(it^i);it=i;
		vis[i^m]=1;
	}
	printf("%d\n",v.size());
	for(auto i:v){
		printf("%d ",i);
	}
}