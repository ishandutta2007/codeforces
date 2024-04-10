#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
int n,a[109];
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	vector<int>ans;
	a[0]=-1;
	for(int i=1;i<=n;++i){
		if(a[i]!=a[i-1])ans.eb(a[i]);
	} 
	for(int i=1;i<=n;++i){
		if(a[i]==a[i-1])ans.eb(a[i]);
	} 
	for(auto o:ans)printf("%d ",o);
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}