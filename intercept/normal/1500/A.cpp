#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n;
int a[M];
vector<pair<int,int>>v[2500009];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j){
			int x=abs(a[i]-a[j]);
			for(auto o:v[x]){
				int u=o.first,v=o.second;
				if(u!=j&&v!=i&&u!=i&&j!=v){
					if(a[u]+a[i]!=a[v]+a[j])swap(u,v);
					printf("YES\n%d %d %d %d\n",u,i,v,j);
					return 0;
				}
			}
			v[x].push_back(pair<int,int>{j,i});
			
		}
	}
	printf("NO\n");
	return 0;
}