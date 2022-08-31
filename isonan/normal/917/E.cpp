#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int n,m,q,son[400010][26],len[400010],fa[400010],cnt=1,last=1,jmp[400010][21],match[400010];
int head[100001],nxt[200001],b[200001],v[200001],k,dep[100001],Fa[100001][21];
int tag[1000001],val[1000001],Pos[1000001],now,size[1000001],Son[1000001],top[1000001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
int node[100001];
char s[100001];
int tem[2][100001],kmp[2][100001],diff[100001],pre[100001];
std::vector<int>pos[2][100001],con[1000001];
std::vector<int>a[100001];
char get(){
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	return ch;
}
int Con[4][100001];
void predo(int x,int f){
	Fa[x][0]=f;
	for(int i=1;i<=20;i++)
		Fa[x][i]=Fa[Fa[x][i-1]][i-1];
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
//			printf("%d %d %d %d\n",x,b[i],v[i],node[x]);
			int tem=node[x];
			for(int j=20;~j;--j)
				if(jmp[tem][j]&&!son[jmp[tem][j]][v[i]])tem=jmp[tem][j];
			if(!son[tem][v[i]]&&son[fa[tem]][v[i]])tem=fa[tem];
			if(son[tem][v[i]])node[b[i]]=son[tem][v[i]];
			else node[b[i]]=tem;
			match[b[i]]=std::min(match[x]+1,len[node[b[i]]]);
			predo(b[i],x);
		}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=20;~i;--i)if(dep[Fa[x][i]]>=dep[y])x=Fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(Fa[x][i]!=Fa[y][i])x=Fa[x][i],y=Fa[y][i];
	return Fa[x][0];
}
int add(int x){
	int p=last;
	len[last=++cnt]=len[p]+1;
	for(;p&&!son[p][x];p=fa[p])son[p][x]=last;
	if(!p)return (fa[last]=1,last);
	int q=son[p][x];
	if(len[q]==len[p]+1)return (fa[last]=q,last);
	len[++cnt]=len[p]+1;
	fa[cnt]=fa[q];
	fa[last]=fa[q]=cnt;
	memcpy(son[cnt],son[q],sizeof son[cnt]);
	for(;son[p][x]==q;p=fa[p])son[p][x]=cnt;
	return last;
}
int ans[100001];
std::vector<int>vec[100001];
namespace solve1{
	int son[200001][26],fail[200001],points,node[2][100001],q[200001],h,t;
	int c[200001],dfn[200001],now,mx[200001];
	void update(int ind,int num){for(;ind<=points+1;ind+=ind&-ind)c[ind]+=num;}
	int query(int ind){
		int tot=0;
		for(;ind;ind-=ind&-ind)tot+=c[ind];
		return tot;
	}
	struct point{
		int v,ord,add;
	};
	std::vector<point>vec[100001];
	std::vector<int>con[200001];
	void dfs(int x){
		dfn[x]=++now;
		for(int i=0;i<con[x].size();i++)
			dfs(con[x][i]);
		mx[x]=now;
	}
	void getans(int x,int f,int node){
//		printf("getans %d %d\n",x,node);
		update(dfn[node],1);
//		for(int i=1;i<=points;i++)printf("%d ",query(i));putchar('\n');
		for(int i=0;i<vec[x].size();i++){
			ans[vec[x][i].ord]+=vec[x][i].add*(query(mx[vec[x][i].v])-query(dfn[vec[x][i].v]-1));
//			if(vec[x][i].ord==4)printf("%d %d %d %d %d %d\n",x,ans[vec[x][i].ord],vec[x][i].ord,vec[x][i].v,query(mx[vec[x][i].v]),query(dfn[vec[x][i].v]-1));
		}
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=f)getans(b[i],x,son[node][v[i]]);
		update(dfn[node],-1);
	}
	void main(){
		for(int i=1;i<=m;i++){
			int now=0;
			for(int j=0;j<a[i].size();j++){
				if(!son[now][a[i][j]])son[now][a[i][j]]=++points;
				now=son[now][a[i][j]];
			}
			node[0][i]=now;
			now=0;
			for(int j=a[i].size()-1;~j;j--){
				if(!son[now][a[i][j]])son[now][a[i][j]]=++points;
				now=son[now][a[i][j]];
			}
			node[1][i]=now;
		}
//		for(int i=0;i<=points;i++){
//			printf("%d ",i);
//			for(int j=0;j<26;j++)
//				if(son[i][j])printf("(%c %d)",j+'a',son[i][j]);
//			putchar('\n');
//		}
		for(int i=0;i<26;i++)
			if(son[0][i])q[++t]=son[0][i];
		while(h<t){
			++h;
			for(int i=0;i<26;i++)
				if(son[q[h]][i])q[++t]=son[q[h]][i],fail[son[q[h]][i]]=son[fail[q[h]]][i];
				else son[q[h]][i]=son[fail[q[h]]][i];
		}
		for(int i=1;i<=points;i++)con[fail[i]].push_back(i);
		dfs(0);
//		for(int i=0;i<=points;i++){
//			printf("-%d %d %d %d\n",i,fail[i],dfn[i],mx[i]);
//		}
		for(int i=1;i<=::q;i++){
			int tem=Con[0][i],len=a[Con[2][i]].size();
//			printf("%d %d %d\n",Con[0][i],Con[1][i],Con[3][i]);
			for(int j=20;~j;--j)
				if(dep[Fa[tem][j]]-dep[Con[3][i]]>=len)tem=Fa[tem][j];
			if(dep[tem]-dep[Con[3][i]]>=len)tem=Fa[tem][0];
			vec[Con[0][i]].push_back((point){node[1][Con[2][i]],i,1});
			if(tem)vec[tem].push_back((point){node[1][Con[2][i]],i,-1});
//			printf("%d %d ",tem,node[1][Con[2][i]]);
			tem=Con[1][i];
			for(int j=20;~j;--j)
				if(dep[Fa[tem][j]]-dep[Con[3][i]]>=len)tem=Fa[tem][j];
			if(dep[tem]-dep[Con[3][i]]>=len)tem=Fa[tem][0];
			vec[Con[1][i]].push_back((point){node[0][Con[2][i]],i,1});
			if(tem)vec[tem].push_back((point){node[0][Con[2][i]],i,-1});
//			printf("%d %d\n",tem,node[0][Con[2][i]]);
		}
		getans(1,0,0);
	}
}
void dfs1(int x){
	size[x]=1;
	for(int i=0;i<con[x].size();i++){
		dfs1(con[x][i]);
		if(size[Son[x]]<size[con[x][i]])Son[x]=con[x][i];
		size[x]+=size[con[x][i]];
	}
}
void dfs2(int x,int t){
	top[x]=t;
	if(Son[x])dfs2(Son[x],t);
	for(int i=0;i<con[x].size();i++)
		if(con[x][i]!=Son[x])dfs2(con[x][i],con[x][i]);
}
void add(int x,int Len){
//	printf("Add %d %d\n",x,val[1]);
	while(x){
		if(tag[top[x]]<now)tag[top[x]]=now,val[top[x]]=-0x7f7f7f7f;
		if(val[top[x]]<std::min(len[x],Len)){
			val[top[x]]=std::min(len[x],Len);
			Pos[top[x]]=Len;
		}
//		printf("%d %d %d\n",x,top[x],std::min(len[x],Len));
		x=fa[top[x]];
	}
}
std::pair<int,int> Que(int x,int Len){
	std::pair<int,int>ans=std::make_pair(0,0);
	while(x){
		if(tag[top[x]]<now)tag[top[x]]=now,val[top[x]]=-0x7f7f7f7f;
//		printf("%d %d %d %d %d\n",x,top[x],val[top[x]],Pos[top[x]],len[x]);
		if(std::min(val[top[x]],std::min(len[x],Len))>ans.first)ans=std::make_pair(std::min(val[top[x]],std::min(len[x],Len)),Pos[top[x]]);
		x=fa[top[x]];
	}
	return ans;
}
struct interval{
	int l,r,d;
};
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
void exgcd(int a,int b,long long &x,long long &y){
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	long long t=x;
	x=y;
	y=t-(a/b)*y;
}
void solve(interval a,interval b,int ord){
//	printf("%d %d %d %d %d %d\n",a.l,a.r,a.d,b.l,b.r,b.d);
	int _gcd=gcd(a.d,b.d);
	if(a.l%_gcd!=b.l%_gcd)return;
	a.d/=_gcd;
	b.d/=_gcd;
	a.l/=_gcd;
	a.r/=_gcd;
	b.l/=_gcd;
	b.r/=_gcd;
	long long x,y;
	exgcd(a.d,b.d,x,y);
	long long X=((1ll*x*(b.l-a.l)*a.d+a.l)%(1ll*a.d*b.d)+(1ll*a.d*b.d))%(1ll*a.d*b.d),mod=1ll*a.d*b.d;
//	printf("%d %d %d %d %d %d %d %d %d %d %d\n",a.l,a.r,a.d,b.l,b.r,b.d,X,x,y,1ll*x*(b.l-a.l)*a.d+a.l,mod);
	long long First=(std::max(a.l,b.l)-X+mod-1)/mod,Second=(std::min(a.r,b.r)-X)/mod;
	if(std::min(a.r,b.r)<X)return;
	ans[ord]+=std::max(Second-First+1,0ll);
//	printf("%d %d %d\n",Second-First+1,First,Second);
//	for(int p1=a.l,p2=b.l;;){
//		if(p1==p2)++ans[ord];
//		if(p1<=p2){
//			if(p1<a.r)p1+=a.d;
//			else return;
//		}
//		else{
//			if(p2<b.r)p2+=b.d;
//			else return;
//		}
//	}
//	ans[ord]+=std::max(second-first,0ll);
}
std::vector<interval>Vec[100001];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		int c=get();
		push(u,v,c-'a'),push(v,u,c-'a');
	}
	for(int i=1;i<=m;i++){
		scanf("%s",s+1);
		int nl=strlen(s+1);
		for(int j=1;j<=nl;j++)a[i].push_back(s[j]-'a');
		for(int j=1;j<=nl;j++)pos[0][i].push_back(add(s[j]-'a'));
		for(int j=nl;j;j--)pos[1][i].push_back(add(s[j]-'a'));
	}
	for(int i=1;i<=cnt;i++)jmp[i][0]=fa[i];
	for(int j=1;j<=20;j++)
		for(int i=1;i<=cnt;i++)
			jmp[i][j]=jmp[jmp[i][j-1]][j-1];
	node[1]=1;
	predo(1,0);
	for(int i=1,u,v,k;i<=q;i++){
		scanf("%d%d%d",&Con[0][i],&Con[1][i],&Con[2][i]);
		Con[3][i]=LCA(Con[0][i],Con[1][i]);
		vec[Con[2][i]].push_back(i);
	}
	solve1::main();
//	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
//	putchar('\n');
//	return 0; 
	for(int i=2;i<=cnt;i++)con[fa[i]].push_back(i);
//	for(int i=1;i<=cnt;i++){
//		printf("%d %d\n",i,fa[i]);
//		for(int j=0;j<26;j++)
//			if(son[i][j])printf("(%c %d)",j+'a',son[i][j]);putchar('\n');
//	}
	dfs1(1);
	dfs2(1,1);
//	for(int i=1;i<=n;i++)printf("%d ",node[i]);putchar('\n');
//	for(int i=1;i<=n;i++)printf("%d ",match[i]);putchar('\n');
//	for(int i=1;i<=q;i++)
//		printf("%d %d %d %d\n",Con[0][i],Con[1][i],Con[2][i],Con[3][i]);
	for(int i=1;i<=m;i++){
		++now;
		for(int j=0;j<pos[1][i].size();j++)add(pos[1][i][j],j+1);
		for(int k=1,j=0;k<=a[i].size();k++){
			if(k>1){
				while(j&&a[i][k-1]!=a[i][j])j=nxt[j];
				if(a[i][k-1]==a[i][j])++j;
				nxt[k]=j;
			}
			diff[k]=k-nxt[k];
			if(diff[k]==diff[nxt[k]])pre[k]=pre[nxt[k]];
			else pre[k]=nxt[k];
		}
//		puts("*");
//		for(int k=1;k<=a[i].size();k++)printf("%d ",nxt[k]);putchar('\n');
//		for(int k=1;k<=a[i].size();k++)printf("%d ",pre[k]);putchar('\n');
//		for(int k=1;k<=a[i].size();k++)printf("%d ",diff[k]);putchar('\n');
		for(int j=0;j<vec[i].size();j++){
			int tem=Con[0][vec[i][j]],top=Con[3][vec[i][j]];
			for(int k=20;~k;--k)
				if(dep[Fa[tem][k]]>=dep[top]&&Que(node[Fa[tem][k]],match[Fa[tem][k]]).first<dep[Fa[tem][k]]-dep[top])
					tem=Fa[tem][k];
			if(Que(node[tem],match[tem]).first<dep[tem]-dep[top])tem=Fa[tem][0];
			Vec[j].clear();
			if(dep[tem]>dep[top]){
				auto now=Que(node[tem],match[tem]);
				int L=now.second-(dep[tem]-dep[top])+1,R=now.second;
//				printf("Queee %d %d %d %d %d %d %d\n",vec[i][j],j,L,R,tem,top,now.first);
				std::swap(L,R);
				L=a[i].size()-L+1;
				R=a[i].size()-R+1;
				int len=R-L+1;
				L=R;
				while(pre[L]>len)L=pre[L];
				int x=(L-len+diff[L]-1)/diff[L];
				R=L-x*diff[L];
//				printf("+%d %d\n",vec[i][j],R);
				while(R){
					Vec[j].push_back((interval){pre[R]+diff[R],R,diff[R]});
					R=pre[R];
				}
			}
		}
		++now;
		for(int j=0;j<pos[0][i].size();j++)add(pos[0][i][j],j+1);
		std::reverse(a[i].begin(),a[i].end());
		for(int k=1,j=0;k<=a[i].size();k++){
			if(k>1){
				while(j&&a[i][k-1]!=a[i][j])j=nxt[j];
				if(a[i][k-1]==a[i][j])++j;
				nxt[k]=j;
			}
			diff[k]=k-nxt[k];
			if(diff[k]==diff[nxt[k]])pre[k]=pre[nxt[k]];
			else pre[k]=nxt[k];
		}
		for(int j=0;j<vec[i].size();j++){
			int tem=Con[1][vec[i][j]],top=Con[3][vec[i][j]];
//			printf("-%d %d\n",tem,top);
			for(int k=20;~k;--k)
				if(dep[Fa[tem][k]]>=dep[top]&&Que(node[Fa[tem][k]],match[Fa[tem][k]]).first<dep[Fa[tem][k]]-dep[top])
					tem=Fa[tem][k];
//			printf("**%d %d %d\n",vec[i][j],tem,top);
			if(Que(node[tem],match[tem]).first<dep[tem]-dep[top])tem=Fa[tem][0];
			if(dep[tem]>dep[top]){
//				printf("%d\n",tem);
				auto now=Que(node[tem],match[tem]);
				int L=now.second-(dep[tem]-dep[top])+1,R=now.second;
//				printf("Queeee %d %d %d %d %d %d\n",vec[i][j],j,L,R,tem,top);
				std::swap(L,R);
				L=a[i].size()-L+1;
				R=a[i].size()-R+1;
				int len=R-L+1;
				L=R;
				while(pre[L]>len)L=pre[L];
				int x=(L-len+diff[L]-1)/diff[L];
				R=L-x*diff[L];
//				printf("-%d %d\n",vec[i][j],R);
				std::vector<interval>Tem;
				while(R){
					Tem.push_back((interval){a[i].size()-R,a[i].size()-pre[R]-diff[R],diff[R]});
					R=pre[R];
				}
				std::reverse(Tem.begin(),Tem.end());
				for(;!Tem.empty()&&!Vec[j].empty();){
					solve(Tem.back(),Vec[j].back(),vec[i][j]);
					if(Tem.back().r<=Vec[j].back().r){
						Tem.pop_back();
					}
					else{
						Vec[j].pop_back();
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}