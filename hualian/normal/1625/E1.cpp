#include<bits/stdc++.h>
#define int long long
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
using namespace std;
#define lowbit(x) (x&-x)
const int N=2e6+9;
bool ppp;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,idx,dfn[N],sz[N];
char s[N];
int sta[N],top;
int id[N],vis[N];
vector<int>e[N];
int sum[N],L[N];
void add(int x,int v){while(x<N)sum[x]+=v,x+=lowbit(x);}
int get(int x,int res=0){if(x<0)return 0;while(x)res+=sum[x],x-=lowbit(x);return res;}
void ADD(int x,int y){e[x].push_back(y);}
void dfs(int x){
	dfn[x]=++idx;
	sz[x]=1;
	int cnt=0;
	for(int i=0;i<e[x].size();i++){
		int to=e[x][i];
		dfs(to),sz[x]+=sz[to];
		cnt+=vis[to];L[to]=cnt;
	}
	if(vis[x])add(dfn[x],cnt*(cnt-1)/2+cnt);
}
bool pppp;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	scanf("%s",s+1);
	rep(i,n)id[i]=i;
	id[0]=n+1;
	rep(i,n){
		if(s[i]=='('){
			sta[++top]=i;
			continue;
		}else{
			if(!top)continue;
			id[i]=id[sta[top]];
			vis[id[i]]=1;
			top--;
			ADD(id[sta[top]],id[i]);
		}
	}
	while(top)ADD(id[sta[top-1]],id[sta[top]]),top--;
	dfs(n+1);
	while(m--){
		int op=read();
		if(op==1){
			
		}else{
			int l=id[read()],r=id[read()];
			int res=get(dfn[r]+sz[r]-1)-get(dfn[l]-1);
			int cnt=L[r]-L[l]+1;
			if(cnt>=0)res+=cnt*(cnt-1)/2+cnt;
			printf("%lld\n",res);
			
		}
	}
	return 0;
}