#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,s[1050];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);m=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k==1){
				s[++m]=k;
			}
			else{
				while(s[m]+1!=k){m--;}
				s[m]=k;
			}
			for(j=1;j<=m;j++){
				printf("%d",s[j]);
				if(j!=m){printf(".");}
			}
			puts("");
		}
	}
}