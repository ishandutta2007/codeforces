#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
using namespace std;
const int N=1005,M=1e5+5;
int t,n,m;
int a[N][N],ans[N][N];
int r[3],ad[3];
char c;
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&t);
	for(;t--;){
		scanf("%d%d",&n,&m);
		fo(i,0,n-1)fo(j,0,n-1)scanf("%d",&a[i][j]),--a[i][j];
		scanf("\n");
		fo(i,0,2)r[i]=i,ad[i]=0;
		fo(i,1,m){
			c=getchar();
			switch(c){
				case 'R':ad[1]=(ad[1]+1)%n;break;
				case 'L':ad[1]=(ad[1]+n-1)%n;break;
				case 'U':ad[0]=(ad[0]+n-1)%n;break;
				case 'D':ad[0]=(ad[0]+1)%n;break;
				case 'I':swap(r[1],r[2]),swap(ad[1],ad[2]);break;
				case 'C':swap(r[0],r[2]),swap(ad[0],ad[2]);break;
			}
		}
		fo(i,0,n-1)fo(j,0,n-1){
			int x[3]={i,j,a[i][j]},y[3];
			fo(i,0,2)y[i]=(x[r[i]]+ad[i])%n;
			ans[y[0]][y[1]]=y[2];
		}
		fo(i,0,n-1){
			fo(j,0,n-1)printf("%d ",ans[i][j]+1);
			printf("\n");
		}
		printf("\n");
	}
}