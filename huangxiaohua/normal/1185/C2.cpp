#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[105],sum,s2;
priority_queue<int> q;

int main(){
	scanf("%d%d",&t,&m);
	for(i=1;i<=t;i++){
		scanf("%d",&k);sum=k;s2=0;
		for(j=1;j<=101;j++){
			if(j==101){printf("0 ");break;}
			if(sum+f[j]*j>m){
				printf("%d ",i-1-s2-(m-sum)/j);break;
			}
			sum+=f[j]*j;s2+=f[j];
		}
		f[k]++;
	}
}