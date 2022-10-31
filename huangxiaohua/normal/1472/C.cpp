#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,k,t,sum,a[200500],used[200500],r;

int get(int k){
	if(used[k]){return 0;}
	used[k]=1;
	if(k+a[k]>n){return k+a[k];}
	return get(k+a[k]);
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		r=0;
		memset(used,0,n*4+50);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			if(used[i]){continue;}
			r=max(r,get(i)-i);
		}
		printf("%d\n",r);
	}
}