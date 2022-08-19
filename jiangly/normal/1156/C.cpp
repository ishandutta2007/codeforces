#include<bits/stdc++.h>
const int MAXN=200000;
int n,z,ans;
int x[MAXN+5];
bool check(int d){
	for(int i=1;i<=d;++i){
		if(x[n-d+i]-x[i]<z){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&z);
	for(int i=1;i<=n;++i){
		scanf("%d",&x[i]);
	}
	std::sort(x+1,x+n+1);
	int l=1,r=n/2,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}