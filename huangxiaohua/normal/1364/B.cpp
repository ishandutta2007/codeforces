#include<bits/stdc++.h>
using namespace std;
 
int n,t,i,j,k,sb[100500],res[100500],tt;
 
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&t);res[0]=1;
		for(i=1;i<=t;i++){
			scanf("%d",&sb[i]);
		}
		if(t==2){printf("2\n%d %d\n",sb[1],sb[2]);continue;}
		res[1]=sb[1];
		for(i=2;i<=t-1;i++){
			if(sb[i]<sb[i-1]&&sb[i]<sb[i+1]){
			res[0]++;res[res[0]]=sb[i];continue;
			}
			if(sb[i]>sb[i-1]&&sb[i]>sb[i+1]){
			res[0]++;res[res[0]]=sb[i];continue;
			}
		}
		if(sb[t]>sb[t-1]&&sb[t-1]<sb[t-2]){res[0]++;res[res[0]]=sb[t];}
		if(sb[t]<sb[t-1]&&sb[t-1]>sb[t-2]){res[0]++;res[res[0]]=sb[t];}
		if(sb[t]<sb[t-1]&&sb[t-1]<sb[t-2]){res[0]++;res[res[0]]=sb[t];}
		if(sb[t]>sb[t-1]&&sb[t-1]>sb[t-2]){res[0]++;res[res[0]]=sb[t];}
		printf("%d\n",res[0]);
		for(i=1;i<=res[0];i++){
			printf("%d ",res[i]);
		}
		puts("");
	}
}