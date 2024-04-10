#include <cstdio>
#include <cstring>

int t,n,p[4001],a[4001],top;
bool f[4001][4001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=(n<<1);i++)scanf("%d",p+i);
		top=0;
		for(int i=1;i<=(n<<1);i++){
			int j=i+1;
			while(p[j]<p[i]&&j<=(n<<1))++j;
			a[++top]=j-i;
			i=j-1;
//			printf("%d\n",j-i);
		}
		for(int i=0;i<=top;i++)
			for(int j=0;j<=n;j++)
				f[i][j]=0;
		f[0][0]=1;
		for(int i=1;i<=top;i++)
			for(int j=0;j<=n;j++){
				f[i][j]=f[i-1][j];
				if(j>=a[i])f[i][j]|=f[i-1][j-a[i]];
			}
		if(f[top][n])puts("YES");
		else puts("NO");
	}
}