#include<bits/stdc++.h>
using namespace std;
int n,a[410000],b[410000];
int getpos(int x,int i){ return lower_bound(b+i+1,b+n+1,x-b[i])-b;}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for (int k=0;k<=24;k++){
		for (int i=1;i<=n;i++) b[i]=(a[i]&((1<<(k+1))-1));
		sort(b+1,b+n+1);
		int tot=0;
		for (int i=1;i<=n;i++){
			tot^=(getpos(1<<(k+1),i)-getpos(1<<k,i))&1;
			tot^=(n+1-getpos((1<<(k+1))+(1<<k),i))&1;
		}
		ans|=(tot<<k);
	}
	printf("%d\n",ans);
	return 0;
}