#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res;
int sb[2000][4];

int main(){
	memset(sb,-1,sizeof(sb));
	for(i=0;i<=5;i++){
		for(j=0;j<=5;j++){
			for(k=0;k<=5;k++){
				sb[i*3+j*5+k*7][1]=i;
				sb[i*3+j*5+k*7][2]=j;
				sb[i*3+j*5+k*7][3]=k;
			}
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);k=0;
		if(n>14){
			k=n/7;k--;
			n-=k*7;
		}
		if(sb[n][1]==-1){
			puts("-1");
		}
		else{
			printf("%d %d %d\n",sb[n][1],sb[n][2],sb[n][3]+k);
		}
	}
}