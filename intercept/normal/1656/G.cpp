#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n;
int a[M],b[M],c[M],d[M];
vector<int>g[M],ans;
bool vis[M];
void work(){
	scanf("%d",&n);
	int n1=0,p=0,mi=1e9,ma=0,num=0,rt=0;
	ans.clear();
	for(int i=1;i<=n;++i)b[i]=vis[i]=0,g[i].clear();
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	for(int i=1;i<=n;++i){
		n1+=b[i]&1;
		if(b[i]&1)p=i;
	}
	if(n1-(n&1)!=0){
		puts("NO");
		return;
	}
	if(n&1){
		for(int i=1;i<=n;++i){
			if(a[i]==p)mi=min(mi,i),ma=max(ma,i);
		}
		if(mi==ma&&mi==(n+1)>>1){
			puts("NO");
			return;
		}
		rt=(mi!=(n+1>>1))?mi:ma;
		vis[rt]=1;
	}
	for(int i=1;i<=n;++i)b[i]=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			if(b[a[i]])c[b[a[i]]]=i,c[i]=b[a[i]],b[a[i]]=0;
			else b[a[i]]=i;
		}
	}
	if(rt){
		int x=n+1>>1,o=1;
		num++;
		g[num].emplace_back(rt);
		do{
			vis[x]=1;
			g[num].emplace_back(x);
			if(o)x=c[x];
			else x=n-x+1;
			o^=1;
		}while(x!=rt);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			num++;
			int x=i,o=1;
			do{
				vis[x]=1;
				g[num].emplace_back(x);
				if(o)x=c[x];
				else x=n-x+1;
				o^=1;
			}while(x!=i);
		}
	}
	for(int i=1;i<=num;++i){
		int len=g[i].size();
		for(int j=0;j<len-1;++j)ans.emplace_back(g[i][j]);
	}
	for(int i=1;i<=num;++i)ans.emplace_back(g[i][int(g[i].size()-1)]);
	ans.emplace_back(g[1][0]);
	for(int i=0;i<ans.size()-1;++i)d[ans[i+1]]=ans[i];
	puts("YES");
	for(int i=1;i<=n;++i)printf("%d%c",d[i]," \n"[i==n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}