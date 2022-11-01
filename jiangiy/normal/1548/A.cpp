#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=200005;
int n,m,ans,a[N];
void add(int x,int y){
	if(x>y)std::swap(x,y);
	if(!a[x]++)ans--;
}
void del(int x,int y){
	if(x>y)std::swap(x,y);
	if(!--a[x])ans++;
}
int main(){
	scanf("%d%d",&n,&m);
	ans=n;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int op,x,y;
		scanf("%d",&op);
		if(op<=2){
			scanf("%d%d",&x,&y);
			if(op==1)add(x,y);
			else del(x,y);
		}
		else{
			printf("%d\n",ans);
		}
	}
}