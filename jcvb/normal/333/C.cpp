#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
int flag[201][10000]={0};
void expand(int x){
	int xx=x;
	int d[5]={0},l=4,tot=0;
	while(x){d[tot++]=x%10;x/=10;}
	int su=0;
	for (int i=0;i<(1<<l);i++){
		for (int ss=0;ss<(1<<l-1);ss++){			
			su=0;int cur;
			for (int j=0;j<l;j++){
				int x;if(1<<j&i)x=d[j];else x=-d[j];
				if(j==0)cur=x;
				else if(ss&1<<j-1)cur*=x;
				else su+=cur,cur=x;
			}
			su+=cur;
			if(su<=200 && su>=1)flag[su][xx]=1;			
		}
	}
}
map<int,bool> bo;
int nee;
void print(int t){
	if(bo[t])return;
	bo[t]=1;
	printf("%08d\n",t);
	nee--;
	if(!nee)exit(0);
}
int main(){
	for (int i=0;i<=9999;i++)expand(i);
	int n;scanf("%d%d",&n,&nee);
	for (int i=n+1;i<=9999 && i-n<=200;i++){
		for (int j=0;j<=9999;j++)if(flag[i-n][j])print(i*10000+j),print(j*10000+i);
	}
	for (int i=n-1;i>=0 && n-i<=200;i--){		
		for (int j=0;j<=9999;j++)if(flag[n-i][j])print(i*10000+j),print(j*10000+i);
	}
	printf("fuck!\n");
	return 0;
}