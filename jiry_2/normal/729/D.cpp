#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b,K,len;
struct atom{
	int fir,tot;
}A[210000];
char ch[210000];
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&K);
	scanf("%s",ch+1);
	int pre=1,tot=0;
	for (int i=1;i<=n+1;i++)
		if (i==n+1||ch[i]=='1'){
			int now=i-pre; tot+=now/b; 
			if (now>=b){
				len++; A[len].fir=pre+b-1;
				A[len].tot=now/b;
			}
			pre=i+1;
		}
	int ans=tot-a+1;
	printf("%d\n",ans);
	for (int i=1;i<=len;i++){
		while (ans&&A[i].tot){
			printf("%d ",A[i].fir); A[i].tot--; ans--; A[i].fir+=b;
		}
	}
	printf("\n");
}