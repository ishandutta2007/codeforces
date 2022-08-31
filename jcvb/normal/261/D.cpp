#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int k,n,maxb,tt;
int b[100005],f[100005];
int ord[100005];
int cmp(int i,int j){
	return b[i]<b[j];
}
int val,tot;
int main()
{
	scanf("%d%d%d%d",&k,&n,&maxb,&tt);
	while(k--){
		for (int i=1;i<=n;i++)scanf("%d",&b[i]),ord[i]=i;
		sort(ord+1,ord+1+n,cmp);
		val=-1,tot=0;
		for (int i=1;i<=n;i++){
			if(b[ord[i]]!=val)val=b[ord[i]],++tot;
			b[ord[i]]=tot;
		}
		int t=min(tt,tot);
		for (int i=0;i<=tot+1;i++)f[i]=0;
		for (int i=1,j=1;i<=n*t;i++,j=(j==n?1:j+1))
			for (int k=b[j]+1;k<=tot+1 && f[b[j]]+1>f[k];k++)
				f[k]=f[b[j]]+1;
		printf("%d\n",f[tot+1]);
	}
	return 0;
}