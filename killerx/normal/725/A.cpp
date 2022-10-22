#include<cstdio>
#include<cstring>
int n;
char c[200005];
int main(){
	scanf("%d%s",&n,c);
	int ans=0;
	for(int i=0;i<n;++i){
		if(c[i]=='>')break;
		++ans;
	}
	for(int i=n-1;~i;--i){
		if(c[i]=='<')break;
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}