#include <cstdio>
#include <algorithm>
using namespace std;

int head[100010],nxt[200010],b[200010],k,f[100010][210],S[210][210],n,K,P=1000000007,size[100010],_ans[210];
typedef long long ll;
inline int add(int a,const int &b){a+=b;return a>=P?a-P:a;}
inline int sub(int a,const int &b){a-=b;return a<0?a+P:a;}
inline int mul(const int &a,const int &b){return (ll)a*b-(ll)a*b/P*P;}
inline int addeq(int &a,const int &b){a+=b;a>=P?a-=P:a;}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int F){
	f[x][0]=size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			for(int j=min(size[x],K);~j;--j)
				for(int k=min(K-j,size[b[i]]);~k;--k){
					int tem=mul(f[x][j],f[b[i]][k]);
					addeq(_ans[j+k+1],tem);
					addeq(_ans[j+k],tem);
					addeq(f[x][j+k+1],tem);
					addeq(f[x][j+k],tem);
				}
			for(int j=0;j<=min(size[b[i]],K);j++)addeq(f[x][j],add(f[b[i]][j],j?f[b[i]][j-1]:0));
			size[x]+=size[b[i]];
		}
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=K;i++)S[i][1]=1;
	for(int i=2;i<=K;i++)
		for(int j=2;j<=i;j++)
			S[i][j]=add(S[i-1][j-1],mul(j,S[i-1][j]));
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s);
	}
	dfs(1,0);
	long long ans=0;
	int fac=1;
	for(int i=0;i<=K;i++){
		ans+=mul(mul(fac,S[K][i]),_ans[i]);
		fac=mul(fac,i+1);
	}
	printf("%I64d\n",ans%P);
}