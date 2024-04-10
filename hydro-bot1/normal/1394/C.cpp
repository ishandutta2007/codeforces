// Hydro submission #62c566208672efa577bec77f@1657103904546
#include<bits/stdc++.h>
using namespace std;
const int M=1e9;char s[500001];
int i,j,n,m,l,r,L,mid,B_cnt,N_cnt,xMin,xMax,yMin,yMax,zMin,zMax,B[300001],N[300001];
bool check(int l){
	xMin=-M,xMax=M,yMin=-M,yMax=M,zMin=-M,zMax=M;
	for (i=1;i<=n;i++){
		xMin=max(xMin,B[i]-l);xMax=min(xMax,B[i]+l);
		yMin=max(yMin,N[i]-l);yMax=min(yMax,N[i]+l);
		zMin=max(zMin,B[i]-N[i]-l);zMax=min(zMax,B[i]-N[i]+l);
	}
	if (xMin>xMax||yMin>yMax||zMin>zMax||xMin-yMax>zMax||xMax-yMin<zMin) return 0;
	B_cnt=min(xMax,yMax+zMax);N_cnt=min(B_cnt-zMin,yMax);L=l;return 1;
}
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%s",s+1);m=strlen(s+1);
		for (j=1;j<=m;j++) B[i]+=(s[j]=='B'),N[i]+=(s[j]=='N');
	}
	for (r=5e5;l<=r;){
		mid=(l+r)>>1;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",L);
	for (i=1;i<=B_cnt;i++) printf("B");
	for (i=1;i<=N_cnt;i++) printf("N");
	return 0;
}