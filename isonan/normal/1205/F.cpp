#include <cstdio>
#include <algorithm>

int f[101][10001],_mul[101],g[101][10001],pre[101][10001][2],node[101][10001],q,n,k,tem[101],G[101][101];
bool check(int n){
	for(int i=1;i<=n;i++){
		int mn=tem[i],mx=tem[i];
		for(int j=i+1;j<=n;j++){
			mn=std::min(mn,tem[j]);
			mx=std::max(mx,tem[j]);
			if(mx-mn+1==j-i+1&&j-i+1<n)return 1;
		}
	}
	return 0;
}
void get(int x){
	for(int i=1;i<=x;i++)tem[i]=i;
	while(check(x)){
		std::random_shuffle(tem+1,tem+x+1);
	}
	for(int i=1;i<=x;i++)G[x][i]=tem[i];
}
int main(){
	scanf("%d",&q);
	for(int i=4;i<=100;i++){
		get(i);
	}
	f[1][0]=1;
	for(int i=1;i<=100;i++)_mul[i]=(i*(i-1))>>1;
	for(int i=2;i<=100;i++){
		for(int j=1;j<=(i*(i-1))>>1;j++)
			for(int k=1;k<=i;k++)
				if(k>=4&&j>=1&&f[i-k+1][j-1]){
					pre[i][j][0]=i-k+1;
					f[i][j]=2;
				}
				else if(j>=_mul[k]&&f[i-k+1][j-_mul[k]]){
					pre[i][j][0]=i-k+1;
					f[i][j]=1;
				}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&n,&k);
		if(k<n){
			puts("NO");
			continue;
		}
		k-=n;
		if(!f[n][k]){
			puts("NO");
			continue;
		}
		else{
			puts("YES");
			int l=1,r=n,last=1;
			while(n){
//				printf("*%d %d %d\n",n,k,f[n][k]);
				if(f[n][k]==1){
					int size=pre[n][k][0];
					if(!last){
						for(int i=1;i<=n-size;i++)printf("%d ",i+l-1);
						l+=n-size;
					}
					else{
						for(int i=1;i<=n-size;i++)printf("%d ",r-i+1);
						r-=n-size;
					}
					last^=1;
					k-=_mul[n-size+1],n=size;
				}
				else{
					int size=pre[n][k][0];
					get(n-size+1);
					int x=G[n-size+1][n-size+1];
					for(int i=1;i<=n-size;i++)printf("%d ",(G[n-size+1][i]<x)?G[n-size+1][i]+l-1:r-(n-size+1-G[n-size+1][i]));
					l+=x-1;
					r=l+size-1;
					--k,n=size;
				}
			}
			putchar('\n');
		}
	}
}