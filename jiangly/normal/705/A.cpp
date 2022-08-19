#include<bits/stdc++.h>
const char*a="I hate ",*b="I love ",*c="that ",*d="it";
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		printf("%s%s",(i&1)?a:b,i==n?d:c);
	}
	return 0;
}