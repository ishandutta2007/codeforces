#include<bits/stdc++.h>
const int N=1e5+6;
int n,cnt;
char s[N];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n-10;++i){
		cnt+=s[i]=='8';
	}
	if(cnt*2<=n-11){
		puts("NO");
	}else{
		puts("YES");
	}
	return 0;
}