#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,it;
ll sum,res,b[500500];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);b[i]*=-1;
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++){
		b[i]*=-1;
		if(sum>=0){res+=sum;}
		sum+=b[i];
		if(it){b[++it]=b[i];}
		if(!it&&sum<0){b[++it]=sum;}
	}
	n=it;
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++){
		res+=(i-1)/(m+1)*b[i];
	}
	printf("%lld",res);
}