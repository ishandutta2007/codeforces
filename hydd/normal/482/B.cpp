#include<bits/stdc++.h>
using namespace std;
int n,q,l[110000],r[110000],x[110000];
int s[32][110000],a[32][110000];
int main(){
	scanf("%d%d",&n,&q);
	for (int k=1;k<=q;k++){
		scanf("%d%d%d",&l[k],&r[k],&x[k]);
		for (int i=30;i>=0;i--)
			if (x[k]&(1<<i)){
				s[i][l[k]]++;
				s[i][r[k]+1]--;
			}
	}
	for (int i=0;i<=30;i++){
		int now=0;
		for (int k=1;k<=n;k++){
			now+=s[i][k];
			a[i][k]=(now!=0);
		}
		for (int k=1;k<=n;k++) s[i][k]=s[i][k-1]+a[i][k];
	}
	bool ans=true;
	for (int k=1;k<=q;k++)
		for (int i=30;i>=0;i--)
			if (!(x[k]&(1<<i))){
				if (s[i][r[k]]-s[i][l[k]-1]==r[k]-l[k]+1) ans=false;
			}
	if (!ans) puts("NO");
	else{
		puts("YES");
		for (int k=1;k<=n;k++){
			int v=0;
			for (int i=0;i<=30;i++) v|=(a[i][k]<<i);
			printf("%d ",v);
		}
	}
	return 0;
}