#include<cstdio>
#include<vector>
#include<algorithm>
using std::sort;
using std::unique;
using std::max;
using std::lower_bound;
using std::upper_bound;
const int N=1000;
int n,m;
int a[N][N],x[N][N],y[N][N],cntx[N],cnty[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&a[i][j]);
			x[i][j]=a[i][j];
			y[j][i]=a[i][j];
		}
	}
	for(int i=0;i<n;++i){
		sort(x[i],x[i]+m);
		cntx[i]=unique(x[i],x[i]+m)-x[i];
	}
	for(int i=0;i<m;++i){
		sort(y[i],y[i]+n);
		cnty[i]=unique(y[i],y[i]+n)-y[i];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			int l=max(lower_bound(x[i],x[i]+cntx[i],a[i][j])-x[i],lower_bound(y[j],y[j]+cnty[j],a[i][j])-y[j]);
			int u=max(x[i]+cntx[i]-upper_bound(x[i],x[i]+cntx[i],a[i][j]),y[j]+cnty[j]-upper_bound(y[j],y[j]+cnty[j],a[i][j]));
			printf("%d ",l+u+1);
		}
		putchar('\n');
	}
	return 0;
}