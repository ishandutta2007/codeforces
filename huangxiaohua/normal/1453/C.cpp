#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,a[2050][2050],res[20];
//int mxx[2050][10],mnx[2050][10],mxy[2050][10],mny[2050][10];
int hx[10],hy[10],lx[10],ly[10];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(res,0,sizeof(res));
		
		for(j=0;j<=9;j++){
			hx[j]=hy[j]=0;
			lx[j]=ly[j]=9999;
		}
		
		/*for(i=1;i<=n;i++){
			for(j=0;j<=9;j++){
				mxx[i][j]=mxy[i][j]=0;
				mnx[i][j]=mny[i][j]=9999;
			}
		}*/
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%1d",&a[i][j]);
				hx[a[i][j]]=max(hx[a[i][j]],i);
				lx[a[i][j]]=min(lx[a[i][j]],i);
				hy[a[i][j]]=max(hy[a[i][j]],j);
				ly[a[i][j]]=min(ly[a[i][j]],j);			
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				k=a[i][j];
				if(hx[k]){
					res[k]=max(res[k],max(j-1,n-j)*(hx[k]-i));
					res[k]=max(res[k],max(j-1,n-j)*(i-lx[k]));
				}
				if(hy[k]){
					res[k]=max(res[k],max(i-1,n-i)*(hy[k]-j));
					res[k]=max(res[k],max(i-1,n-i)*(j-ly[k]));
				}
			}
		}
		/*for(i=0;i<=9;i++){
			printf("%d %d %d %d\n",hx[i],lx[i],hy[i],ly[i]);
		}*/
		for(i=0;i<=9;i++){
			printf("%d ",res[i]);
		}puts("");
	}
}