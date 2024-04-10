#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
char s[100005];
int a[100005];
int n;
int su[100005][3]={0};
int tmp[3];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1;i<=n;i++)a[i]=s[i-1]-'x';
	for (int i=1;i<=n;i++){
		for (int k=0;k<3;k++)su[i][k]=su[i-1][k];
		su[i][a[i]]++;
	}
	int que;scanf("%d",&que);
	while(que--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(r-l<=1){
			printf("YES\n");
			continue;
		}
		for (int k=0;k<3;k++)tmp[k]=su[r][k]-su[l-1][k];
		sort(tmp,tmp+3);
		if(tmp[2]-tmp[0]<=1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}