#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=500005,INF=0x8000000;
int n,m,fa[N];
std::vector<int>ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int k,x,y;
		scanf("%d%d",&k,&x);
		if(k==1)y=INF;
		else{
			scanf("%d",&y);
			if(x==y)y=INF;
			else if(x>y)std::swap(x,y);
		}
		while(1){
			if(x==INF)break;
			if(!fa[x]){
				fa[x]=y==INF?-1:y;
				ans.push_back(i);
				break;
			}
			if(fa[x]==-1){
				x=y;
				y=INF;
				continue;
			}
			if(fa[fa[x]])fa[x]=fa[fa[x]];
			if(fa[x]==-1){
				x=y;
				y=INF;
				continue;
			}
			x=fa[x];
			if(x==y)break;
			if(x>y)std::swap(x,y);
		}
	}
	int uans=1;
	for(int i=0;i<ans.size();i++)uans=uans*2%1000000007;
	printf("%d %d\n",uans,(int)ans.size());
	for(int x:ans)printf("%d ",x);
	puts("");
}