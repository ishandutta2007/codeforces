#include<bits/stdc++.h>
using namespace std;
int n,a[110000],num[110000],ans;
int main(){
	scanf("%d",&n); a[1]=0;
	int u,v;
	for (int i=2;i<=n;i++){
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		scanf("%d",&v); a[i]=v;
	}
	int x=0,y=0,z=0;
	for (int i=1;i<=n;i++){
		if (num[a[i]]){
			x=num[a[i]]; y=i;
			break;
		}
		num[a[i]]=i;
	}
	if (x){
		printf("AND %d %d\n",x,y);
		fflush(stdout);
		scanf("%d",&v);
		ans=a[x]^v;
	} else{
		z=(num[n-1]==2)?3:2;
		printf("AND %d %d\n",1,z);
		fflush(stdout);
		scanf("%d",&v);
		printf("AND %d %d\n",num[n-1],z);
		fflush(stdout);
		scanf("%d",&u);
		ans=a[z]^(u|v);
	}
	printf("! %d",ans);
	for (int i=2;i<=n;i++) printf(" %d",ans^a[i]);
	return 0;
}