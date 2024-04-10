#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
//#define int long long
#pragma GCC optimize(2)
 
const int BLOCK=400,CNT=500;
int pos[200001],a[200001],b[200001],add[CNT+1],dfn[200001],mx[200001],ord[200001],tem[CNT+1][BLOCK+1],now,n,q;
int q1[CNT+1][BLOCK+1],q2[CNT+1][BLOCK+1],tmp[BLOCK+1],now1[CNT+1],now2[CNT+1];
int head[200001],nxt[200001],_b[200001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	_b[k]=t;
}
bool cmp(int lhs,int rhs){return b[lhs]<b[rhs];}
long long INT1(int lhs,int rhs){
	long long up=1ll*a[rhs]*b[rhs]-1ll*a[lhs]*b[lhs];
	up=(up+b[lhs]-b[rhs]-1)/(b[lhs]-b[rhs]);
//	if(up<0)return 10000000000000000ll;
	return up;
}
long long INT2(int lhs,int rhs){
	long long up=1ll*a[rhs]*b[rhs]-1ll*a[lhs]*b[lhs];
	up=up/(b[lhs]-b[rhs]);
//	if(up<0)return 10000000000000000ll;
	return up;
}
long long eval(int x){
	return 1ll*(add[pos[dfn[x]]]+a[x])*b[x];
}
void update(int x){
	while(now1[x]<*(q1[x])&&eval(q1[x][now1[x]])<=eval(q1[x][now1[x]+1]))++now1[x];
//	while(now2[x]>1&&eval(q1[x][now2[x]])>=eval(q1[x][now2[x]-1]))--now2[x];
	while(now2[x]<*(q2[x])&&eval(q2[x][now2[x]])>=eval(q2[x][now2[x]+1]))++now2[x];
}
void rebuild(int x){
	int top=0;
//	if(x==4)putchar('&');
	for(int i=(x-1)*BLOCK+1;pos[i]==x;i++){
		++top;
		tmp[top]=tem[x][top];
//		if(x==4)printf("%d ",eval(tmp[top]));
	}
//	if(x==4)putchar('\n');
	int *Q1=q1[x],*Q2=q2[x];
	Q1[0]=0;
	for(int i=1;i<=top;i++){
		if(*Q1>0&&b[Q1[*Q1]]==b[tmp[i]]){
			if((a[Q1[*Q1]]<a[tmp[i]])^(b[tmp[i]]<0))--*Q1;
			else continue;
		}
		while(*Q1>1&&INT1(tmp[i],Q1[*Q1-1])<=INT1(Q1[*Q1],Q1[*Q1-1]))--*Q1;
		Q1[++*Q1]=tmp[i];
	}
	*Q2=0;
	for(int i=top;i;i--){
		if(*Q2>0&&b[Q2[*Q2]]==b[tmp[i]]){
			if((a[Q2[*Q2]]>a[tmp[i]])^(b[tmp[i]]<0))--*Q2;
			else continue;
		}
		while(*Q2>1&&INT2(tmp[i],Q2[*Q2-1])<=INT2(Q2[*Q2],Q2[*Q2-1]))--*Q2;
		Q2[++*Q2]=tmp[i];
	}
//	if(x==4){
//		putchar('*');
//		for(int i=1;i<=q2[x][0];i++)printf("%d ",eval(q2[x][i]));putchar('\n');
//	}
	now1[x]=now2[x]=1;
	update(x);
//	printf("%d %d\n",eval(q1[x][now1[x]]),eval(q2[x][now2[x]]));
}
void dfs(int x){
	dfn[x]=++now;
	ord[now]=x;
	for(int i=head[x];i;i=nxt[i]){
		a[_b[i]]+=a[x];
		b[_b[i]]+=b[x];
		dfs(_b[i]);
	}
	mx[x]=now;
}
inline long long abs(const long long &x){return x<0?-x:x;}
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
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=2,tem;i<=n;i++)push(read(),i);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	dfs(1);
	for(int i=1;i<=n;i++)pos[i]=(i-1)/BLOCK+1;
	for(int i=1;i<=pos[n];i++){
		int top=0;
		for(int j=(i-1)*BLOCK+1;pos[j]==i;j++){
			tem[i][++top]=ord[j];
		}
		std::sort(tem[i]+1,tem[i]+top+1,cmp);
	}
	for(int i=1;i<=pos[n];i++)rebuild(i);
	for(int i=1,opt,u,v;i<=q;i++){
		opt=read();
		if(opt==1){
			u=read(),v=read();
			int l=dfn[u],r=mx[u];
			if(pos[l]==pos[r]){
				for(int j=l;j<=r;j++)a[ord[j]]+=v;
				rebuild(pos[l]);
			}
			else{
				if(pos[l]==pos[l-1]){
					for(;pos[l]==pos[l-1];l++)a[ord[l]]+=v;
					rebuild(pos[l]-1);
				}
				if(pos[r]==pos[r+1]){
					for(;pos[r]==pos[r+1];r--)a[ord[r]]+=v;
					rebuild(pos[r]+1);
				}
				for(int j=pos[l];j<=pos[r];j++)add[j]+=v,update(j);
			}
		}
		else{
			u=read();
			int l=dfn[u],r=mx[u];
			long long ans=0;
			if(pos[l]==pos[r]){
				for(int j=l;j<=r;j++)ans=std::max(ans,abs(eval(ord[j])));
			}
			else{
				for(;pos[l]==pos[l-1];l++)ans=std::max(ans,abs(eval(ord[l])));
				for(;pos[r]==pos[r+1];r--)ans=std::max(ans,abs(eval(ord[r])));
				for(int j=pos[l];j<=pos[r];j++)ans=std::max(ans,std::max(abs(eval(q1[j][now1[j]])),abs(eval(q2[j][now2[j]]))));
			}
			write(ans);
			putchar('\n');
		}
//		for(int i=1;i<=n;i++)printf("%d ",eval(ord[i]));putchar('\n');
//		for(int i=1;i<=pos[n];i++)rebuild(i),printf("%d %d\n",eval(q1[i][now1[i]]),eval(q2[i][now2[i]]));
	}
}