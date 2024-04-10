#include <cstdio>
#include <algorithm>

int t,n,f[100001];
char A[100001],B[100001],cnt1[21],cnt2[21];
bool vis[21][21];
int find(int x){
	return (f[x]!=x)?f[x]=find(f[x]):x;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		scanf("%s%s",A+1,B+1);
		for(int i=0;i<20;i++)f[i]=i;
		for(int i=0;i<20;i++)
			for(int j=0;j<20;j++)
				vis[i][j]=0;
		bool cando=1;
		for(int i=1;i<=n;i++)
			if(A[i]>B[i])cando=0;
			else if(A[i]<B[i])f[find(A[i]-'a')]=find(B[i]-'a');
		if(!cando)puts("-1");
		else{
			int tot=20;
			for(int i=0;i<20;i++)if(f[i]==i)--tot;
			printf("%d\n",tot);
		}
	}
}