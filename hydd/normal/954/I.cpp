#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,a[510000],b[510000],c[11];
int nxt[510000],ans[510000];
char s[510000],t[510000];
void KMP(int x){
	for (int i=2,j=0;i<=m;i++){
		while (j&&b[i]!=b[j+1]) j=nxt[j];
		if (b[i]==b[j+1]) j++;
		nxt[i]=j;
	}
	for (int i=1,j=0;i<=n;i++){
		while (j&&a[i]!=b[j+1]) j=nxt[j];
		if (a[i]==b[j+1]) j++;
		if (j==m){
			ans[i]=min(ans[i],x);
			j=nxt[j];
		}
	}
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1); m=strlen(t+1);
	for (int i=1;i<=n;i++) ans[i]=INF;
	c[5]=5;
	for (c[0]=0;c[0]<=5;c[0]++)
		for (c[1]=1;c[1]<=5;c[1]++)
			for (c[2]=2;c[2]<=5;c[2]++)
				for (c[3]=3;c[3]<=5;c[3]++)
					for (c[4]=4;c[4]<=5;c[4]++){
						for (int i=1;i<=n;i++) a[i]=c[s[i]-'a'];
						for (int i=1;i<=m;i++) b[i]=c[t[i]-'a'];
						KMP((c[0]!=0)+(c[1]!=1)+(c[2]!=2)+(c[3]!=3)+(c[4]!=4));
					}
	for (int i=m;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}