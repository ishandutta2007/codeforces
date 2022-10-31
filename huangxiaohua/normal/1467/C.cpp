#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,n,m,l,a,b,c,j;
ll s1,s2,s3,res;
int main(){
	a=b=c=2e9;res=1e17;
	scanf("%d%d%d",&n,&m,&l);
	for(i=1;i<=n;i++){
		scanf("%d",&j);s1+=j;a=min(a,j);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&j);s2+=j;b=min(b,j);
	}
	for(i=1;i<=l;i++){
		scanf("%d",&j);s3+=j;c=min(c,j);
	}
	res=min(0ll+a+b,res);
	res=min(0ll+a+c,res);
	res=min(0ll+c+b,res);
	res=min(s1,res);
	res=min(s2,res);
	res=min(s3,res);
	printf("%lld\n",s1+s2+s3-2*res);
}