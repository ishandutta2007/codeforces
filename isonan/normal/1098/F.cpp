#include <cstdio>
#include <vector>
#include <cstring> 
#include <algorithm>

char str[200010];
int n,son[400010][26],len[400010],fa[400010],pos[400010],cnt=1,last=1;
void add(int x){
	int p=last;
	len[last=++cnt]=len[p]+1;
	for(;p&&!son[p][x];p=fa[p])son[p][x]=last;
	if(!p)return (void)(fa[last]=1);
	int q=son[p][x];
	if(len[q]==len[p]+1)return (void)(fa[last]=q);
	fa[++cnt]=fa[q];fa[q]=fa[last]=cnt;
	len[cnt]=len[p]+1;
	memcpy(son[cnt],son[q],sizeof son[cnt]);
	for(;son[p][x]==q;p=fa[p])son[p][x]=cnt;
}
std::vector<int>que[200010];
int head[400010],nxt[400001],b[400010],k;
int L[200010],R[200010],q;
long long ans[200010];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int size[400010],Son[400010],top[400010],Fa[400010];
void dfs(int x,int f){
	Fa[x]=f;
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			if(size[Son[x]]<size[b[i]])Son[x]=b[i];
			size[x]+=size[b[i]];
		}
}
int tem[400010][2],Top;
int now;
struct BIT{
	long long c1[400010],c2[400010];
	int tag[400010];
	void update(int ind,long long num,long long *c){
		for(;ind<=n+1;ind+=ind&-ind){
			if(tag[ind]<now)tag[ind]=now,c1[ind]=c2[ind]=0;
			c[ind]+=num;
		}
	}
	long long query(int ind,long long *c){
		long long tot=0;
		for(;ind;ind-=ind&-ind){
			if(tag[ind]<now)tag[ind]=now,c1[ind]=c2[ind]=0;
			tot+=c[ind];
		}
		return tot;
	}
	void Add(int x,int y,int z){
		update(x,y,c1);
		update(x,z,c2);
	}
	long long Query(int l,int r,long long k,long long b){
		if(l>r)return 0;
		long long tot=0;
		if(k)tot+=(query(r,c2)-query(l-1,c2))*k;
		if(b)tot+=(query(r,c1)-query(l-1,c1))*b;
		return tot;
	}
}bit;
struct query{int val,t,type,ord;};
bool cmp(const query &a,const query &b){return a.t<b.t||(a.t==b.t&&a.type<b.type);}
void get(int x,int f,int len){
	if(pos[x]){
		++Top;
		tem[Top][0]=pos[x];
		tem[Top][1]=len;
	}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)get(b[i],x,len);
}
void getans(int x){
	for(int i=x;i;i=Son[i])
		for(int j=head[i];j;j=nxt[j])
			if(b[j]!=Fa[i]&&b[j]!=Son[i])
				getans(b[j]);
	Top=0;
	for(int i=x;i;i=Son[i]){
		for(int j=head[i];j;j=nxt[j])
			if(b[j]!=Fa[i]&&b[j]!=Son[i]){
				int cnt=Top;
				get(b[j],i,len[i]);
				++now;
				for(int k=cnt+1;k<=Top;k++)bit.Add(tem[k][0],1,tem[k][0]);
				for(int k=cnt+1;k<=Top;k++){
					int u=tem[k][0];
					for(int l=0;l<que[u].size();l++){
						int L=::L[que[u][l]],R=::R[que[u][l]],Len=len[i];
						ans[que[u][l]]-=bit.Query(L,R-Len,0,1)*Len;
						ans[que[u][l]]-=bit.Query(std::max(L,R-Len+1),R,-1,R+1);
					}
				}
			}
		if(pos[i]){
			++Top;
			tem[Top][0]=pos[i];
			tem[Top][1]=len[i];
		}
	}
	++now;
	for(int i=1;i<=Top;i++){
		int u=tem[i][0];
		bit.Add(u,1,tem[i][1]);
		for(int j=0;j<que[u].size();j++)
			ans[que[u][j]]+=bit.Query(L[que[u][j]],R[que[u][j]]-tem[i][1],1,0);
	}
	for(int i=1;i<=Top;i++){
		int u=tem[i][0];
		bit.Add(u,-1,-tem[i][1]);
		for(int j=0;j<que[u].size();j++)
			ans[que[u][j]]+=bit.Query(L[que[u][j]],R[que[u][j]]-tem[i][1],0,1)*tem[i][1];
	}
	std::vector<query>vec;
	for(int i=1;i<=Top;i++){
		int u=tem[i][0];
		vec.push_back((query){u+tem[i][1],u,0,0});
//		printf("%d %d %d\n",x,u,tem[i][1]);
		for(int j=0;j<que[u].size();j++){
			int L=std::max(::L[que[u][j]],::R[que[u][j]]-tem[i][1]+1),R=::R[que[u][j]];
//			printf("%d %d %d %d\n",que[u][j],ans[que[u][j]],L,R);
			vec.push_back((query){R+1,L-1,1,que[u][j]});
			vec.push_back((query){R+1,R,2,que[u][j]});
		}
	}
	std::sort(vec.begin(),vec.end(),cmp);
	long long sum=0;
	++now;
	for(int i=0;i<vec.size();i++)
		if(!vec[i].type)bit.Add(vec[i].val,1,vec[i].val),sum+=vec[i].t;
		else{
			int coe=vec[i].type==1?-1:1;
			ans[vec[i].ord]+=(bit.Query(1,vec[i].val-1,1,0)+bit.Query(vec[i].val,n+1,0,1)*(vec[i].val)-sum)*coe;
		}
	vec.clear();
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(long long x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=n;i;i--)add(str[i]-'a'),pos[last]=i;
	for(int i=2;i<=cnt;i++)push(fa[i],i);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		L[i]=read(),R[i]=read();
		que[L[i]].push_back(i);
	}
	dfs(1,0);
	getans(1);
	for(int i=1;i<=q;i++)write(ans[i]),putchar('\n');
}