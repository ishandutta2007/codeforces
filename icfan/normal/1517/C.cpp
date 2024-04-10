#include <cstdio>
const int Maxn=500;
int p[Maxn+5];
int a[Maxn+5][Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++){
		a[i][i]=p[i];
		int x=i,y=i;
		for(int j=1;j<p[i];j++){
			if(y>1&&a[x][y-1]==0){
				y--;
			}
			else{
				x++;
			}
			a[x][y]=p[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			printf("%d%c",a[i][j]," \n"[j==i]);
		}
	}
	return 0;
}