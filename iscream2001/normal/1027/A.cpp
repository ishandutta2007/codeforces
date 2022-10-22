#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int a[200];
char s[200];
int main(){
	int T;scanf("%d",&T);
	bool flag;
	while(T--){
		scanf("%d%s",&n,s+1);m=n/2;
		for(int i=1;i<=n;++i) a[i]=s[i];
		flag=0;
		for(int i=1;i<=m;++i){
			if(a[i]==a[n-i+1]||abs(a[i]-a[n-i+1])==2)continue;
			flag=1;break;
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}