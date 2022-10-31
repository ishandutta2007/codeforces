#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t;
ll a[1050][1050],s1[1050],s2[1050],k,sb,d;

int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
			s1[i]+=a[i][j];
			s2[i]+=a[i][j]*a[i][j];
		}
	}
	for(i=2;i<n;i++){
		if(s1[i+1]-s1[i]==s1[i]-s1[i-1]){
			sb=s2[i-1]+s2[i+1]-2*s2[i];d=s1[i+1]-s1[i];break;
		}
	}
	for(i=2;i<n;i++){
		if(s1[i]-s1[i-1]==d||s1[i+1]-s1[i]==d){continue;}
		printf("%d ",i-1);
		for(j=1;j<=m;j++){
			k=(s1[i-1]+s1[i+1])/2-s1[i]+a[i][j];
			if(s2[i-1]+s2[i+1]-(s2[i]-a[i][j]*a[i][j]+k*k)*2==sb){
				printf("%lld",k);return 0;
			}
		}
	}
	return 1;
}