#include<bits/stdc++.h>
using namespace std;
int t1,t2,t3,t4,n,m;
int f[4100][4100],lsts[4100][26],lstt[4100][26];
char s[4100],t[4100];
int main(){
	scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
	scanf("%s",s+1); scanf("%s",t+1);
	n=strlen(s+1); m=strlen(t+1);
	f[0][0]=0;
	for (int i=1;i<=n;i++){
		f[i][0]=t2*i;
		for (int c=0;c<26;c++) lsts[i][c]=lsts[i-1][c];
		lsts[i][s[i]-'a']=i;
	}
	for (int i=1;i<=m;i++){
		f[0][i]=t1*i;
		for (int c=0;c<26;c++) lstt[i][c]=lstt[i-1][c];
		lstt[i][t[i]-'a']=i;
	}
	int x,y;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			f[i][j]=min(min(f[i-1][j]+t2,f[i][j-1]+t1),f[i-1][j-1]+(s[i]==t[j]?0:t3));
			x=lsts[i-1][t[j]-'a']; y=lstt[j-1][s[i]-'a'];
			if (x&&y) f[i][j]=min(f[i][j],f[x-1][y-1]+t4+(i-x-1)*t2+(j-y-1)*t1);
		}
	printf("%d\n",f[n][m]);
	return 0;
}