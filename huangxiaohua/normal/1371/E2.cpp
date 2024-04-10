#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[100500],st,ed=2e9;

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		st=max(st,a[i]-i+1);
		if(i>=m){
			ed=min(ed,a[i]+m-i-1);
		}
	}
	printf("%d\n",max(ed-st+1,0));
	for(i=st;i<=ed;i++){
		printf("%d ",i);
	}
}