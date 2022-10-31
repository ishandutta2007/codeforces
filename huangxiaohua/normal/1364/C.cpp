#include<bits/stdc++.h>
using namespace std;
 
int n,t,i,j,k,sb[100500],jb[100500],res=0;
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&sb[i]);
		jb[sb[i]]=1;
		if(sb[i]>i){puts("-1");return 0;}
	}
	for(i=1;i<=n;i++){
		if(sb[i]!=sb[i-1]&&i>=1&&i>1){printf("%d ",sb[i-1]);continue;}
		while(jb[res]==1){res++;}
		printf("%d ",res);res++;
	}
}