#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n,m;
int a[M];
char s[M];
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;++i)a[i]=(s[i]-'a'+1)+a[i-1];
	for(int i=1,l,r;i<=m;++i){
		scanf("%d%d",&l,&r);
		printf("%d\n",a[r]-a[l-1]);
	}
	return 0;
}