// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,n,m,q[maxn],x,fla;
int a[maxn],b[maxn],ans[maxn];
vector<int> c[maxn];
int main(){
	T=read();
	for (int opt=1;opt<=T;opt++){
		n=read(); m=read(); fla=0;
		for (i=1;i<=n;i++){
			a[i]=0; b[i]=0;
		}
		for (i=1;i<=m;i++){
			c[i].clear();
		}
		for (i=1;i<=m;i++){
			q[i]=read();
			for (j=1;j<=q[i];j++){
				c[i].push_back(read());
			}
			if (q[i]==1){
				a[c[i][0]]++;
			}
		}
		for (i=1;i<=n;i++){
			if (a[i]>(m/2)+(m%2)){
				printf("NO\n");
				fla=1;
			}
		}
		if (fla==1) continue;
		for (i=1;i<=m;i++){
			if (q[i]==1){
				b[i]=c[i][0];
			}
			else{
				x=c[i][0];
				for (j=1;j<q[i];j++){
					if (a[x]>a[c[i][j]]) x=c[i][j];
				}
				b[i]=x; a[x]++;
			}
		}
		printf("YES\n");
		for (i=1;i<=m;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	return 0;
}