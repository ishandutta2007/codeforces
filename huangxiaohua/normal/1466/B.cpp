#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,sb[305500],sb2[305500],res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=0;
		memset(sb,0,n*4*2+50);
		memset(sb2,0,n*4*2+50);
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			sb[k]++;
		}
		for(i=1;i<=n*2+3;i++){
			if(sb2[i]){res++;sb2[i+1]+=sb[i];continue;}
			if(sb[i]){res++;sb2[i+1]+=(sb[i]-1);continue;}
		}
		printf("%d\n",res);
	}
}