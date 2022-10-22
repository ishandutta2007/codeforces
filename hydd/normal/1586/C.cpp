#include<bits/stdc++.h>
using namespace std;
int n,m,Q,a[1100000],b[1100000]; char s[1100000];
int c[1100000];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++){
			a[j]=(s[j]=='X');
			if (a[j]&&b[j+1]) c[j+1]=1;
			b[j]=a[j];
		}
	}
	for (int i=2;i<=m;i++) c[i]+=c[i-1];
	scanf("%d",&Q); int x,y;
	while (Q--){
		scanf("%d%d",&x,&y);
		if (c[x]==c[y]) puts("YES");
		else puts("NO");
	}
	return 0;
}