#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char ch[110000];
int n,len,A[110000];
int main(){
	scanf("%d",&n);
	scanf("%s",ch+1);
	int pre=1,flag=0,num=0;
	for (int i=2;i<=n+1;i++)
		if (i>n||ch[i]!=ch[pre]){
			A[++len]=i-pre; pre=i;
			if (A[len]>2) flag=1; else if (A[len]==2) num++;
		}
	if (flag||num>=2) printf("%d\n",len+2);
	else if (num) printf("%d\n",len+1);
	else printf("%d\n",len);
	return 0;
}