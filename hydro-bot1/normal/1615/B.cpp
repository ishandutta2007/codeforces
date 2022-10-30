// Hydro submission #61cc6284cb38e9d32635730b@1640784516733
#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int _,n,s[N+5][25],l,r;
int main(){
	scanf("%d",&_);
	for(int i=1;i<=N;i++){
		int t=i;
		for(int j=1;t;t/=2,j++){
			s[i][j]=s[i-1][j];
			if(t&1)s[i][j]++;
		}
	}
	while(_--){
		scanf("%d%d",&l,&r);
		int min1=1e9;
		for(int i=1;i<=20;i++){
			min1=min(min1,r-l+1-(s[r][i]-s[l-1][i]));
		}
		printf("%d\n",min1);
	}
}