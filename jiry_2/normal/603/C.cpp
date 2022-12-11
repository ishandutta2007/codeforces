#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int sg[110000],n,K,pd[5];
const int N=100000;
int find1(int k1){
	if (k1<N) return sg[k1];
	if (k1&1) return 0;
	int k2=find1(k1/2); if (k2!=1) return 1; else if (k2==1) return 2;
}
int find2(int k1){
	if (k1<N) return sg[k1];
	if (k1&1) return 0; else return 1;
}
int main(){
	scanf("%d%d",&n,&K);
	sg[0]=0; sg[1]=1;
	for (int i=2;i<=100000;i++){
		memset(pd,0x00,sizeof pd);
		if (i&1) pd[sg[i-1]]=1;
		else{
			pd[sg[i-1]]=1;
			if (K&1) pd[sg[i/2]]=1; else pd[0]=1;
		}
		for (int j=0;;j++) if (pd[j]==0) {sg[i]=j; break;}
	}
	int num=0;
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1);
		if (K&1) num^=find1(k1); else num^=find2(k1);
	}
	if (num) printf("Kevin\n"); else printf("Nicky\n");
	return 0;
}