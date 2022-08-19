#include <cstdio>
#include <cstring>
#include <algorithm>

int n,a,b,s[5001],R[5001],F[5001];
int low[5001],dfn[5001],stk[5010],top,now,S,Ans[5001],g[5001][5001];
int cnt1[2000010],cnt2[2000010],C[5010][5010];
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
bool instack[5001],vis[2000001],A[5001][5001];
std::vector<int>ans[5001],vec[5001];
std::pair<int,int>in[5010];
void tarjan(int x){
	low[x]=dfn[x]=++now;
	instack[x]=1;
	stk[++top]=x;
	for(int i=1;i<=n;i++)
		if(A[x][i]){
			if(!dfn[i])tarjan(i),low[x]=std::min(low[x],low[i]);
			else if(instack[i])low[x]=std::min(low[x],dfn[i]);
		}
	if(low[x]==dfn[x]){
		++S;
		while(stk[top+1]!=x){
			Ans[stk[top]]=S;
			g[S][S]=gcd(g[S][S],s[stk[top]]);
			vec[S].push_back(stk[top]);
			instack[stk[top]]=0;
			--top;
		}
	}
}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%1000000007;
		a=1ll*a*a%1000000007;
		b>>=1;
	}
	return ans;
}
int read(){
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	return ch=='1';
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			A[i][j]=read();
	for(int i=1;i<=n;i++){
		scanf("%d",s+i);
		ans[i].resize(s[i]);
		for(int j=0;j<s[i];j++)
			R[i]+=ans[i][j]=read();
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
//	for(int i=1;i<=n;i++)printf("*%d %d\n",i,Ans[i]);
	for(int i=S;i;i--){
		for(int j=i;j>=1&&j>=i-1;j--){
			if(j<i)g[i][j]=gcd(g[i][j+1],g[j][j]);
//			printf("%d %d %d\n",i,j,g[i][j]);
			if(j==i||g[i][j]!=g[i][j+1]){
				memset(vis,0,(g[i][j]+1));
				for(int k=0;k<vec[i].size();k++){
					for(int l=0;l<s[vec[i][k]];l++)
						if(ans[vec[i][k]][l])vis[l%g[i][j]]=1;//,printf("%d\n",l%g[i][j]);
				}
			}
			for(int k=0;k<vec[j].size();k++){
//				printf("-%d %d %d\n",j,vec[j][k],g[i][j]);
				for(int l=0;l<s[vec[j][k]];l++)
					if(vis[l%g[i][j]])ans[vec[j][k]][l]=1;//,printf("%d %d\n",l,l);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<s[i];j++)
			F[i]+=ans[i][j];//,printf("%d %d %d\n",i,j,ans[i][j]);
	for(int i=1;i<=n;i++)++cnt1[R[i]],++cnt2[F[i]];
	for(int i=1;i<=2000000;i++)cnt2[i]+=cnt2[i-1];
	for(int i=1999999;~i;i--)cnt1[i]+=cnt1[i+1];
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%1000000007;
	}
	int ans=0;
//	for(int i=1;i<=n;i++)printf("%d %d\n",F[i],R[i]);
	for(int i=1;i<=n;i++)in[i]=std::make_pair(R[i],F[i]);
	std::sort(in+1,in+n+1);
	std::reverse(in+1,in+n+1);
	for(int i=1;i<=n;i++){
		int c1=0,c2=0;
		for(int j=1;j<=n;j++){
			if(in[j].first>in[i].second)++c1;
			else if(in[j].second>in[i].second)++c2;
			else if(in[j].second==in[i].second&&j<i)++c2;
		}
		if(c1>=a)continue;
		for(int j=std::min(b,std::min(a-1-c1,c2));j>=0&&b-1-j<=c1;--j)
			ans=(1ll*ans+1ll*C[c2][j]*C[c1][b-1-j])%1000000007;
	}
	printf("%d\n",ans);
	return 0;
}