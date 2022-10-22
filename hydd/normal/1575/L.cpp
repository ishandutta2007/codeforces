#include<bits/stdc++.h>
using namespace std;
int n,tree[210000];
vector<int> vec[210000];
void add(int x,int y){
	for (;x<=n;x+=x&-x) tree[x]=max(tree[x],y);
}
int query(int x){
	int res=0;
	for (;x;x-=x&-x) res=max(res,tree[x]);
	return res;
}
int main(){
	scanf("%d",&n); int x;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x<=i) vec[i-x].push_back(x);
	}
	for (int i=0;i<=n;i++){
		sort(vec[i].begin(),vec[i].end());
		for (int v:vec[i]) add(v,query(v-1)+1);
	}
	printf("%d\n",query(n));
	return 0;
}