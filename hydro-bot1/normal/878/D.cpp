// Hydro submission #62c6750e8672efa577bfa1cf@1657173262946
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,K=12;
bitset<1<<K>f[N+K];
int n,k,q,cnt,a[K^1][N],b[N][K^1];
int main(){
	scanf("%d%d%d",&n,&k,&q),cnt=k;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]),b[j][i]=i;
	for(int i=1;i<=n;i++)
		sort(b[i]+1,b[i]+1+k,[&](const int&x,const int&y)->bool{
			return a[x][i]==a[y][i]?x>y:a[x][i]>a[y][i];
		});
	for(int i=1;i<=k;i++)
		for(int j=0;j<1<<k;j++)
		if(j&1<<(i-1))f[i][j]=1;
	for(int i=1,op,x,y;i<=q;i++){
		scanf("%d%d%d",&op,&x,&y);
		switch(op){
			case 1:f[++cnt]=f[x]|f[y];break;
			case 2:f[++cnt]=f[x]&f[y];break;
			case 3:
				for(int i=1,t=0;i<=k;i++){
					t|=1<<(b[y][i]-1);
					if(f[x][t]){
						printf("%d\n",a[b[y][i]][y]);
						break;
					}
				}
				break;
		}
	}
	return 0;
}