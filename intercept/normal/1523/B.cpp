#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
int n;
int c[2009];
vector<int>a;
vector<vector<int>>b;
void work(){
	int ans=0;
	b.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i+=2){
		ans++;
		a={1,i,i+1};
		b.eb(a);
		ans++;
		a={2,i,i+1};
		b.eb(a);
		ans++;
		a={1,i,i+1};
		b.eb(a);
		ans++;
		a={1,i,i+1};
		b.eb(a);
		ans++;
		a={2,i,i+1};
		b.eb(a);
		ans++;
		a={1,i,i+1};
		b.eb(a);
	}
	printf("%d\n",ans);
	for(auto v:b){
		printf("%d %d %d\n",v[0],v[1],v[2]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}