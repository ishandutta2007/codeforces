#include<bits/stdc++.h>
const int N=1e5+5;
int n,ans;
int a[5];
char s[N];
int main(){
	for(int i=1;i<=4;++i){
		scanf("%d",&a[i]);
	}
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		ans+=a[s[i]-'0'];
	}
	printf("%d\n",ans);
	return 0;
}