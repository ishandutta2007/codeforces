#include<bits/stdc++.h>
const int N=2e5+5;
int n,t,c,ans;
int a[N];
int l,r;
int q[N];
int main(){
	scanf("%d%d%d",&n,&t,&c);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		while(l!=r&&i-q[l]>=c){
			++l;
		}
		while(l!=r&&a[q[r-1]]<=a[i]){
			--r;
		}
		q[r++]=i;
		ans+=i>=c&&a[q[l]]<=t;
	}
	printf("%d\n",ans);
	return 0;
}