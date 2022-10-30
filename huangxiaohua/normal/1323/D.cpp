#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,t,n,a[400500],b0[400500],b1[400500],n0,n1,ans,l,r;
ll res[66];

int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=25;i++){
		n0=n1=0;
		for(j=1;j<=n;j++){
			if(a[j]&b(i)){
				b1[++n1]=(a[j]&(b(i)-1));
			}
			else{
				b0[++n0]=(a[j]&(b(i)-1));
			}
		}
		sort(b0+1,b0+n0+1);
		sort(b1+1,b1+n1+1);
		l=1;r=n0;
		for(;l<=n0;l++){
			for(;((b0[r]+b0[l])>=b(i));r--){}
			res[i]+=max(0,n0-max(r,l));
		}
		//printf("%d ",res[i]);
		l=1;r=n1;
		for(;l<=n1;l++){
			for(;((b1[r]+b1[l])>=b(i));r--){}
			res[i]+=max(0,n1-max(r,l));
		}
		//printf("%d ",res[i]);
		l=1;r=n1;
		for(;l<=n0;l++){
			for(;((b1[r]+b0[l])>=b(i));r--){}
			res[i]+=r;
		}
		//printf("%d ",res[i]);puts("");
		if(res[i]&1){ans|=b(i);}
	}
	printf("%d",ans);
}