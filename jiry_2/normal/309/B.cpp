#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
char ch[5000010],s[5001000];
int n,R,len,c,r[1000010],pre[1001000],f[1001000];
int main(){
	scanf("%d%d%d",&n,&R,&c);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1); int k1=strlen(s+1);
		for (int j=1;j<=k1;j++) ch[j+len]=s[j]; len+=k1; r[i]=len;
	}
	int now=0;
	for (int i=1;i<=n;i++){
		while (r[i]-r[now]+i-now-1>c) now++; pre[i]=now;
	}
	memcpy(f,pre,sizeof pre);
//	for (int i=1;i<=n;i++) cout<<pre[i]<<" "; cout<<endl;
	for (int i=R-1;i;i>>=1){
		if (i&1) for (int j=n;j;j--) pre[j]=f[pre[j]];
		for (int j=n;j;j--) f[j]=f[f[j]];
	}
	int where=0,num=-1;
	for (int i=1;i<=n;i++) if (i-pre[i]>num){num=i-pre[i]; where=pre[i];}
//	for (int i=1;i<=n;i++) cout<<pre[i]<<" "; cout<<endl;
	for (int i=1;i<=R;i++){
		int now=where;
		while (now<=n&&r[now]-r[where]+now-where-1<=c) now++; now--;
		for (int j=where+1;j<=now;j++){
			for (int k1=r[j-1]+1;k1<=r[j];k1++) putchar(ch[k1]); if (j!=now) putchar(' ');
		}
		putchar('\n'); where=now;
	}
	return 0;
}