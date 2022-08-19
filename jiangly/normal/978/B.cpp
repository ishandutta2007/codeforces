#include<bits/stdc++.h>
const int MAXN=100;
int n,cnt,ans;
char a[MAXN+5];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<=n;++i){
		cnt=a[i]=='x'?cnt+1:0;
		ans+=cnt>=3;
	}
	printf("%d\n",ans);
	return 0;
}