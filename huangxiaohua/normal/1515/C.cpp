#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],res[100500],x;
unordered_map<int,bool> mp;

priority_queue<pair<int,int> >q;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&x);
		puts("YES");
		while(!q.empty()){
			q.pop();
		}
		for(i=1;i<=m;i++){
			q.push({0,i});
		}
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			auto [u,v]=q.top();q.pop();
			printf("%d ",v);
			q.push({u-k,v});
		}
		puts("");
	}
}