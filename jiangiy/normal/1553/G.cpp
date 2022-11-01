#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=150005,M=1000005;
int n,q,pc,s[N],p[M/7],id[M],lo[M],fa[M/7];
std::vector<PI>ok;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int main(){
	for(int i=2;i<=M-1;i++){
		if(!lo[i])id[i]=pc,p[pc++]=i,lo[i]=i;
		for(int j=0;i*p[j]<M;j++){
			lo[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	for(int i=0;i<pc;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		int lst=-1,t=s[i];
		while(t!=1){
			if(~lst)merge(id[lst],id[lo[t]]);
			lst=lo[t],t/=lo[t];
		}
	}
	for(int i=1;i<=n;i++){
		int lst=-1,x=s[i]+1,cx=0,px[50];
		while(x!=1)px[cx++]=find(id[lo[x]]),x/=lo[x];
		x=s[i];
		while(x!=1)px[cx++]=find(id[lo[x]]),x/=lo[x];
		std::sort(px,px+cx);
		cx=std::unique(px,px+cx)-px;
		for(int i=0;i<cx;i++) for(int j=0;j<i;j++)ok.push_back(MP(px[j],px[i]));
	}
	std::sort(ok.begin(),ok.end());
	ok.resize(std::unique(ok.begin(),ok.end())-ok.begin());
	while(q--){
		int x,y,cx=0,cy=0,px[30],py[30];
		scanf("%d%d",&x,&y);
		x=find(id[lo[s[x]]]),y=find(id[lo[s[y]]]);
		if(x==y){
			puts("0");
			continue;
		}
		if(x>y)std::swap(x,y);
		int t=std::lower_bound(ok.begin(),ok.end(),MP(x,y))-ok.begin();
		if(t<ok.size()&&ok[t]==MP(x,y))puts("1");
		else puts("2");
	}
}