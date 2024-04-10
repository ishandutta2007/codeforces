#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[300500],res;
int x,y,z,tmp,tmp2;

bool chk(int i){
	if(i<=1||i>=n){return 0;}
	if(a[i]>a[i-1]&&a[i]>a[i+1]){return 1;}
	if(a[i]<a[i-1]&&a[i]<a[i+1]){return 1;}
	return 0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);tmp=0;res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(n<3){puts("0");continue;}
		for(i=2;i<n;i++){
			res+=chk(i);
		}
		for(i=1;i<=n;i++){
			tmp2=a[i];
			x=y=z=0;
			x=chk(i-1)+chk(i)+chk(i+1);
			if(i>1){a[i]=a[i-1];y=chk(i-1)+chk(i)+chk(i+1);}
			if(i<n){a[i]=a[i+1];z=chk(i-1)+chk(i)+chk(i+1);}
			tmp=max(tmp,x-min(y,z));
			a[i]=tmp2;
		}
		printf("%d\n",res-tmp);
	}
}