#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int l,r,n;
int main(){
	int l=-1e9,r=1e9;
	int now=0; scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		if (k2==1) l=max(l,1900-now);
		else r=min(r,1899-now);
		now+=k1;
	//	cout<<now<<" "<<l<<" "<<r<<endl;
	}
	if (l>r) printf("Impossible\n");
	else {
		int ans=r+now;
		if (ans>2e8) printf("Infinity\n"); else printf("%d\n",ans);
	}
	return 0;
}