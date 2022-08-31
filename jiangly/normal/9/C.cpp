#include<bits/stdc++.h>
int n,ans;// something
int dec(int x){
	int ans=0;
	for(int i=9;i>=0;--i)
		ans=ans*10+(x>>i&1);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,j=dec(i);j<=n;++i,j=dec(i))
		++ans;
	printf("%d\n",ans);
	return 0;
}