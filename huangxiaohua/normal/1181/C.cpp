#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,u[1050][1050],l[1050][1050],it,k1,k2,k3,k4,k5,k6;
ll res;
char s[1050][1050];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s[i]+1;
	}
	for(i='a';i<='z';i++){
		for(j=1;j<=n;j++){
			it=0;
			for(k=1;k<=m;k++){
				if(s[j][k]!=i){
					it=0;continue;
				}
				if(!it){it=k;}
				l[j][k]=it;
			}
		}
		for(k=1;k<=m;k++){
			it=0;
			for(j=1;j<=n;j++){
				if(s[j][k]!=i){
					it=0;continue;
				}
				if(!it){it=j;}
				u[j][k]=it;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			k1=u[i][j];
			k2=u[k1-1][j];
			if(!k2){continue;}
			k3=u[k2-1][j];
			if(!k3){continue;}
			if((i-k1+1)==(k1-k2)&&(k1-k2)<=(k2-k3)){
				int nmsl=1e9,len=(k1-k2)*3;
				for(k=i;k>i-len;k--){
					nmsl=min(nmsl,j-l[k][j]+1);
				}
				res+=nmsl;
			}
		}
	}
	printf("%lld",res);
}