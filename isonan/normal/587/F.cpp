#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int son[400001][27],fa[400001],dfn[400001],mx[400001],now,n,cnt=1,last=1,pre[400001][21],end[400001],length[400001],q,len[400001];
int pos[400001],sum,block,head[800001],nxt[800001],b[800001],k;
int posi[400001],val[400001];
long long ans[100001];
char str[400001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
struct point{int l,orig,flag,k;};
bool cmp(point a,point b){return a.l<b.l;}
std::vector<point>vec[100001],all;
std::vector<int>exi[100001];
void add(int x){
	int p=last;
	len[last=++cnt]=len[p]+1;
	for(;p&&!son[p][x];p=fa[p])son[p][x]=last;
	if(!p)return (void)(fa[last]=1);
	int q=son[p][x];
	if(len[q]==len[p]+1)return (void)(fa[last]=q);
	len[++cnt]=len[p]+1;
	fa[cnt]=fa[q];
	fa[q]=fa[last]=cnt;
	memcpy(son[cnt],son[q],sizeof son[cnt]);
	for(;p&&son[p][x]==q;p=fa[p])son[p][x]=cnt;
}
void dfs(int x,int key){
	val[x]=0;
	if(posi[x]==key)++val[x];
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i],key),val[x]+=val[b[i]];
}
void dfs2(int x){
	dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		dfs2(b[i]);
	mx[x]=now;
}
namespace sqrt_tech{
	int pos[400001],block,n,v[400001],add[400001];
	void init(int x){
		n=x;
		block=sqrt(x);
		for(int i=1;i<=n;i++)pos[i]=(i-1)/block+1;
	}
	void update(int l,int r){
		if(pos[r]-pos[l]<=1)for(int i=l;i<=r;++i)++v[i];
		else{
			for(int i=l;pos[i]==pos[l];++i)++v[i];
			for(int i=pos[l]+1;i<pos[r];++i)++add[i];
			for(int i=r;pos[i]==pos[r];--i)++v[i];
		}
	}
	int query(int x){return v[x]+add[pos[x]];}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		length[i]=strlen(str+1);
		sum+=length[i]+1;
		for(int j=1;str[j];++j)add(str[j]-'a'),posi[last]=i,exi[i].push_back(last);
		pos[i]=last;
		memset(str+1,0,length[i]);
		add(26);
	}
	for(int i=1;i<=cnt;i++)pre[i][0]=fa[i],push(fa[i],i);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=cnt;i++)
			pre[i][j]=pre[pre[i][j-1]][j-1];
	for(int i=1;i<=n;i++)
		for(int j=20;~j;--j)
			if(len[pre[pos[i]][j]]>=length[i])pos[i]=pre[pos[i]][j];
	block=sqrt(sum);
	for(int i=1,l,r,k;i<=q;i++){
		scanf("%d%d%d",&l,&r,&k);
		if(length[k]>block)vec[k].push_back((point){l-1,i,-1,0}),vec[k].push_back((point){r,i,1,0});
		else all.push_back((point){l-1,i,-1,k}),all.push_back((point){r,i,1,k});
	}
	for(int i=1;i<=n;i++)
		if(length[i]>block){
			std::sort(vec[i].begin(),vec[i].end(),cmp);
			dfs(1,i);
			int now=0;
			while(now<vec[i].size()&&vec[i][now].l==0)++now;
			long long sum=0;
			for(int j=1;j<=n;j++){
				sum+=val[pos[j]];
				while(now<vec[i].size()&&vec[i][now].l==j){
					ans[vec[i][now].orig]+=vec[i][now].flag*sum;
					++now;
				}
			}
		}
	dfs2(1);
	std::sort(all.begin(),all.end(),cmp);
	sqrt_tech::init(cnt);
	int now=0;
	while(now<all.size()&&all[now].l==0)++now;
	for(int i=1;i<=n;i++){
		sqrt_tech::update(dfn[pos[i]],mx[pos[i]]);
		while(now<all.size()&&all[now].l==i){
			for(int j=0;j<exi[all[now].k].size();++j)
				ans[all[now].orig]+=all[now].flag*sqrt_tech::query(dfn[exi[all[now].k][j]]);
			++now;
		}
	}
	for(int i=1;i<=q;i++)printf("%I64d\n",ans[i]);
}