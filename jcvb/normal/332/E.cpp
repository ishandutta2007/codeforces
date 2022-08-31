#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define se 10007
using namespace std;
char p[1000005];int lp,ls;
char s[205];
int k;
char ansstr[2005]={0};
char ans[2005];
int hap[1000005],has[2005];

int check(int t){
	for (int i=ls-1;i>=0;i--)
		has[i]=(i+t<ls?has[i+t]:0)*se+s[i];
	int i,j;
	for (i=t-1,j=k-1;j>=0;j--){
		if(i>=0&& hap[j]==has[i]){
			ans[j]='1';
			i--;
		}else ans[j]='0';
	}
	if(i>=0)ans[0]=0;
}
int main()
{
	char c;
	lp=0;
	while((c=getchar())!='\n')p[lp++]=c;p[lp]=0;
//	scanf("%s",p);
	//lp=strlen(p);
//	scanf("%s",s);
	//ls=strlen(s);
	ls=0;
	while((c=getchar())!='\n')s[ls++]=c;s[ls]=0;
	scanf("%d",&k);
	for (int i=lp-1;i>=0;i--)
		hap[i]=(i+k<lp?hap[i+k]:0)*se+p[i];
	for (int t=1;t<=k;t++)
	//	if(lp/k*t<=ls && (lp/k+1)*t>=ls && lp%k>=ls%t && k-lp%k >= t-ls%t){
		{
			check(t);
			if(ans[0] && (!ansstr[0] || strcmp(ans,ansstr)==-1))strcpy(ansstr,ans);
		}
	if(!ansstr[0])printf("0\n");
	else puts(ansstr);
	return 0;
}