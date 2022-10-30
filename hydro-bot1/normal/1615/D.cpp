// Hydro submission #61cc62abdf7a55d3530abd62@1640784556112
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int _,n,m;
vector<pair<int,int> > e[N];
int f[N<<1],fff;
struct Ans{int x,y,s;}ans[N];
int getanc(int k){return f[k]==k?k:f[k]=getanc(f[k]);}
void he(int x,int y){if(getanc(x)!=getanc(y))f[getanc(x)]=y;}
bool work(int x){
	bool s=1;
	for(;x;x>>=1)if(x&1)s=!s;
	return s;
}
void dfs(int x,int fa){
	for(auto i:e[x]){
		int y=i.first,z=i.second;
		if(y==fa)continue;
		if(z!=-1){
			if(work(z))he(x,y),he(x+n,y+n);
			else he(x,y+n),he(x+n,y);
		}
		dfs(y,x);
	}
}
int main(){
	scanf("%d",&_);
	while(_--){
		int ff=0;
//		if(_==20000-161)fff=1;
		scanf("%d%d",&n,&m);
//		if(fff)cout<<n<<' '<<m<<endl;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=2*n;i++)f[i]=i;
		for(int i=1,x,y,z;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
//			if(fff)cout<<x<<' '<<y<<' '<<z<<endl;
			e[x].emplace_back(y,z);
			e[y].emplace_back(x,z);
			ans[i]=(Ans){x,y,z};
		}
		dfs(1,0);
		for(int i=1,x,y,p;i<=m;i++){
			scanf("%d%d%d",&x,&y,&p);
//			if(fff)cout<<x<<' '<<y<<' '<<p<<endl;
			if(p==1){
				if(getanc(x)==getanc(y)||getanc(x+n)==getanc(y+n))ff=1;
				he(x,y+n),he(y,x+n);
			}
			else{
				if(getanc(x)==getanc(y+n)||getanc(x+n)==getanc(y))ff=1;
				he(x,y),he(y+n,x+n);
			}
		}
//		if(fff)return 0;
//		if(_>=200)continue;
		if(ff)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<n;i++){
				if(ans[i].s==-1){
					if(getanc(ans[i].x)==getanc(ans[i].y)||getanc(ans[i].x+n)==getanc(ans[i].y+n))ans[i].s=0;
					else{
						ans[i].s=1;
						he(ans[i].x,ans[i].y+n);
						he(ans[i].x+n,ans[i].y);
					} 
				}
				printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].s);
			}
		}
	}
}