#include<cstdio>
using namespace std;
int n,m,x,y;
double a[1100][1100],f[1100];
void Gauss(int n){
    for (int i=1;i<=n;i++){
    	if (i<n) a[i][i+1]/=a[i][i];
    	a[i][n+1]/=a[i][i]; a[i][i]=1;
        a[i+1][i+1]-=a[i+1][i]*a[i][i+1];
        a[i+1][n+1]-=a[i+1][i]*a[i][n+1];
        a[i+1][i]=0;
    }
    for (int i=n-1;i>=1;i--) a[i][n+1]-=a[i][i+1]*a[i+1][n+1];
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&x,&y);
	n-=(x-1); x=1;
    if (m==1){
		printf("%.10lf\n",(double)2*(n-1));
		return 0;
	}
	for (int i=1;i<n;i++){
		a[1][1]=2; a[1][2]=-1; a[1][m+1]=3+f[1];
		a[m][m]=2; a[m][m-1]=-1; a[m][m+1]=3+f[m];
		for (int j=2;j<m;j++){
			a[j][j]=3; a[j][j-1]=-1;
			a[j][j+1]=-1; a[j][m+1]=4+f[j];
		}
		Gauss(m);
		for (int j=1;j<=m;j++) f[j]=a[j][m+1];
	}
	printf("%.10lf\n",f[y]);
	return 0;
}