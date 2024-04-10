#include <cstdio>
#include <vector>
#include <algorithm>

int n,d[250001],num[250001],con[250001][3],top;
long long f[250001][2];
bool vis[250001],del[250001];
std::vector<int>vec[250001],edge[250001];
void addedge(int s,int t,int val){
	++top;
	con[top][0]=s;
	con[top][1]=t;
	con[top][2]=val;
	vec[s].push_back(top);
	vec[t].push_back(top);
	edge[s].push_back(top);
	edge[t].push_back(top);
}
bool cmp1(int a,int b){return d[a]>d[b];}
bool cmp2(int a,int b){return con[a][2]<con[b][2];}
bool cmp3(int a,int b){return d[con[a][0]]+d[con[a][1]]>d[con[b][0]]+d[con[b][1]];}
int pre[2000001],nxt[2000001],cnt,Now[250001],point[250001][2];
long long sum[250001],v[2000001];
long long ans[250001];
void delnode(int x,int y){
//	printf("delnode %d\n",y);
	pre[nxt[y]]=pre[y];
	nxt[pre[y]]=nxt[y];
	if(y<=Now[x]){
		Now[x]=nxt[Now[x]];
		sum[x]=sum[x]-v[y]+v[Now[x]];
	}
}
int Newnode(int x,long long val){
	++cnt;
	v[cnt]=val;
	nxt[x]=cnt;
	pre[cnt]=x;
	return cnt;
}
long long getans(int x,int F,int now){
	vis[x]=0;
	long long s=0;
	std::vector<long long>tem;
	for(int i=0;i<edge[x].size();i++){
		int u=con[edge[x][i]][0]^con[edge[x][i]][1]^x;
		if(d[u]<=now)break;
		else if(u!=F){
			getans(u,x,now);
			s+=f[u][0];
			tem.push_back(f[u][1]+con[edge[x][i]][2]-f[u][0]);
		}
	}
	std::sort(tem.begin(),tem.end());
	f[x][0]=f[x][1]=3e11;
	long long val=sum[x];
//	printf("%d %lld\n",x,sum[x]);
	for(int i=0,point=Now[x];i<=tem.size();i++){
		f[x][0]=std::min(f[x][0],val);
		if(i<tem.size()){
			val-=v[point],point=(pre[point]?pre[point]:point);
			val+=tem[i];
		}
	}
	val=sum[x]-v[Now[x]];
	for(int i=0,point=pre[Now[x]];i<=tem.size();i++){
		f[x][1]=std::min(f[x][1],val);
		if(i<tem.size()){
			val-=v[point],point=(pre[point]?pre[point]:point);
			val+=tem[i];
		}
	}
	f[x][0]+=s,f[x][1]+=s;
//	printf("check %d %lld %lld %lld\n",x,f[x][0],f[x][1],s);
	return f[x][0];
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v,val;i<n;i++)scanf("%d%d%d",&u,&v,&val),addedge(u,v,val),++d[u],++d[v];
	for(int i=1;i<=n;i++)num[i]=i;
	std::sort(num+1,num+n+1,cmp1);
	for(int i=1;i<=n;i++){
		std::sort(vec[i].begin(),vec[i].end(),cmp2);
		std::sort(edge[i].begin(),edge[i].end(),cmp3);
		Now[i]=Newnode(0,0);
		int last=Now[i]; 
		for(int j=0;j<vec[i].size();j++){
			last=Newnode(last,con[vec[i][j]][2]);
			point[vec[i][j]][i==con[vec[i][j]][1]]=last;
		}
		for(int j=0;j<d[i];j++)last=Newnode(last,2e6);
	}
	for(int i=n-1,now;~i;i--){
		now=0;
		while(now<n&&d[num[now+1]]>i)++now;
		for(int j=1;j<=now;j++){
			Now[num[j]]=nxt[Now[num[j]]];
			sum[num[j]]+=v[Now[num[j]]];
		}
		for(int j=now;j;j--){
			if(del[j])break;
			del[j]=1;
			for(int k=0;k<edge[num[j]].size();k++){
				int u=edge[num[j]][k],v=con[u][0]^con[u][1]^num[j];
				delnode(v,point[u][con[u][1]==v]);
			}
		}
		for(int j=1;j<=now;j++)vis[num[j]]=1;
		for(int j=1;j<=now;j++)if(vis[num[j]])ans[i]+=getans(num[j],0,i);
//		printf("getans %d\n",i);
//		for(int i=1;i<=cnt;i++)printf("%d %d %d %lld\n",i,nxt[i],pre[i],v[i]);
//		for(int i=1;i<=n;i++)printf("%d ",Now[i]);putchar('\n');
//		for(int i=1;i<=n;i++)printf("%lld ",sum[i]);putchar('\n');
	}
	for(int i=0;i<n;i++)printf("%lld ",ans[i]);
}