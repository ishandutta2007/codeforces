#include <cstdio>
#include <cstring>
#include <algorithm>

int son[20001][11],cnt,len[20001],n,f[2001][20001],sl,sr,g[2001][20001];
int sum[20001][2001],fail[20001],q[20001],h,t;
char l[801],r[801];
int Newnode(int x){
	++cnt;
	len[cnt]=len[x]+1;
	return cnt;
}
int main(){
	scanf("%s%s%d",l+1,r+1,&n);
	sl=strlen(l+1);
	sr=strlen(r+1);
	int p=-1;
	if(sl==sr){
		p=0;
		for(p=1;p<=sl;p++)
			if(l[p]!=r[p])break;
	}
	for(int i=1,now=0;i<=sl;i++){
		if(i>p)
			for(int j=l[i]-'0'+1;j<10;j++){
				if(!son[now][j])son[now][j]=Newnode(now);
				++sum[son[now][j]][sl];
			}
		else if(i==p)
			for(int j=l[i]-'0'+1;j<r[i]-'0';j++){
				if(!son[now][j])son[now][j]=Newnode(now);
				++sum[son[now][j]][sl];
			}
		if(!son[now][l[i]-'0'])son[now][l[i]-'0']=Newnode(now);
		now=son[now][l[i]-'0'];
		if(i==sl&&p<=sl)++sum[now][sl];
	}
	for(int i=1,now=0;i<=sr;i++){
		if(i>p)
			for(int j=1;j<r[i]-'0';j++){
				if(!son[now][j])son[now][j]=Newnode(now);
				++sum[son[now][j]][sr];
			}
		if(!son[now][r[i]-'0'])son[now][r[i]-'0']=Newnode(now);
		now=son[now][r[i]-'0'];
		if(i==sr)++sum[now][sr];
	}
	for(int i=sl+1;i<sr;i++){
		for(int j=1;j<10;j++){
			if(!son[0][j])son[0][j]=Newnode(0);
			++sum[son[0][j]][i];
		}
	}
	for(int i=0;i<10;i++)
		if(son[0][i])q[++t]=son[0][i];
	while(h<t){
		++h;
		for(int i=len[q[h]]-len[fail[q[h]]];i<=n;i++)sum[q[h]][i]+=sum[fail[q[h]]][i-(len[q[h]]-len[fail[q[h]]])];
		for(int i=0;i<10;i++)
			if(son[q[h]][i])fail[son[q[h]][i]]=son[fail[q[h]]][i],q[++t]=son[q[h]][i];
			else son[q[h]][i]=son[fail[q[h]]][i];
	}
//	for(int i=0;i<=cnt;i++){
//		printf("%d %d: \n",i,len[i]);
//		for(int j=0;j<10;j++)
//			if(son[i][j])printf("(\"%c\" %d)",j+'0',son[i][j]);putchar('\n');
//		for(int j=0;j<=800;j++)
//			if(sum[i][j])printf("(%d %d)",j,sum[i][j]);putchar('\n');
//	}
	memset(f,-0x7f7f7f7f,sizeof f);
	for(int j=0;j<=cnt;j++)f[n][j]=0;
	for(int i=0;i<=cnt;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]+=sum[i][j-1];
	for(int i=n-1;~i;i--)
		for(int j=0;j<=cnt;j++)
			for(int k=0;k<10;k++){
				int u=son[j][k];
				if(f[i+1][u]+((n-i-1+len[u]>=0)?sum[u][std::min(n-i-1+len[u],n)]:0)>f[i][j]){
					f[i][j]=f[i+1][u]+((n-i-1+len[u]>=0)?sum[u][std::min(n-i-1+len[u],n)]:0);
					g[i][j]=k;
//					printf("%d %d %d %d %d %d %d %d\n",i,j,k,f[i][j],u,n-i-1+len[u],sum[u][n-i-1+len[u]],f[i+1][u]);
				}
			}
	printf("%d\n",f[0][0]);
	for(int i=1,now=0;i<=n;i++){
		putchar(g[i-1][now]+'0');
		now=son[now][g[i-1][now]];
	}
}