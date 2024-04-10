#include <cstdio>
#include <vector>

std::vector<int>cc;
int t,n,m;
int head[100001],nxt[200010],b[200010],k=1,d[100001];
int ans[100001];
bool vis[100001];
bool get;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f,std::vector<int>&cc=::cc){
	if(vis[x])return;
	vis[x]=1;
	cc.push_back(x);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x,cc);
}
bool walk(int x,int f,int end){
	ans[x]=2;
	if(x==end)return 1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)
			if(walk(b[i],x,end))return 1;
	ans[x]=1;
	return 0;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)head[i]=d[i]=vis[i]=ans[i]=0;
		k=1;
		for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u),++d[u],++d[v];
		get=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				cc.clear();
				dfs(i,0);
				int sum=0;
				for(int i=0;i<cc.size();i++)sum+=d[cc[i]];
				if((sum>>1)>=cc.size()){
					get=1;
					for(int j=0;j<cc.size();j++)ans[cc[j]]=1;
					break;
				}
				sum=0;
				int p=0,p2=0;
				for(int i=0;i<cc.size();i++){
					if((!p)||d[p]<d[cc[i]])p=cc[i];
				}
				for(int i=0;i<cc.size();i++){
					if(cc[i]!=p&&((!p2)||d[p2]<d[cc[i]]))p2=cc[i];
				}
				if(d[p]>=4)p2=p;
				if(d[p]>=3){
					for(int i=0;i<cc.size();i++)ans[cc[i]]=1;
					walk(p,0,p2);
					for(int i=0;i<cc.size();i++){
						sum-=ans[cc[i]]*ans[cc[i]]*2;
						for(int j=head[cc[i]];j;j=nxt[j])
							sum+=ans[b[j]]*ans[cc[i]];
					}
					if(sum>=0){
						get=1;
						break;
					}
					else{
						for(int i=0;i<cc.size();i++)ans[cc[i]]=0;
					}
				}
				if(d[p]==3){
					int cnt=0;
					std::vector<int>vec[3];
					for(int i=0;i<cc.size();i++)vis[cc[i]]=0;
					vis[p]=1;
					for(int i=head[p];i;i=nxt[i]){
						dfs(b[i],p,vec[cnt++]);
						while(vec[cnt-1].size()>6)vec[cnt-1].pop_back();
					}
					ans[p]=(vec[0].size()+1)*(vec[1].size()+1)*(vec[2].size()+1);
					for(int fd=0;fd<3;fd++){
						int last=ans[p];
						for(int i=0;i<vec[fd].size();i++)
							last=(ans[vec[fd][i]]=(last/(vec[fd].size()+1-i))*(vec[fd].size()-i));
					}
					int sum=0;
					for(int i=0;i<cc.size();i++){
						sum-=ans[cc[i]]*ans[cc[i]]*2;
						for(int j=head[cc[i]];j;j=nxt[j])
							sum+=ans[b[j]]*ans[cc[i]];
					}
					if(sum>=0){
						get=1;
						break;
					}
					else{
						for(int i=0;i<cc.size();i++)ans[cc[i]]=0;
					}
				}
			}
		if(!get)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);putchar('\n');
		}
	}
}