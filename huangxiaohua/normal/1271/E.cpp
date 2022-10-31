#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,m1,m2;
ll n,m,b1[66],b2[66],l,r,sum,md,res=1,sb1,sb2;
ll f(int x){
	x++;return (x>0)?(1ll<<x)-1:0;
}

ll get(ll md){
	n=md;m2=0;sum=0;
	memset(b2,0,sizeof(b2));
	while(n){
		if(n&1){b2[m2+1]=1;}m2++;n>>=1;
	}
	for(i=m2;i>=1;i--){
		if(b2[i]<b1[i-m2+m1]){sum+=f(m1-m2);goto aaa;}
		if(b2[i]>b1[i-m2+m1]){sum+=f(m1-m2-1);goto aaa;}
	}
	sum+=f(m1-m2-1);
	sum++;
	for(i=1;i<=m1-m2;i++){
		sum+=b1[i]*(1ll<<(i-1));
	}
	aaa:;
	return sum;
}

int main(){
	scanf("%lld%lld",&n,&m);
	l=1;r=n;
	while(n){
		if(n&1){b1[m1+1]=1;}m1++;n>>=1;
	}
	while(l<=r){
		md=(l+r)>>1;
		if(!(md&1)){md++;}
		sb1=get(md);sb2=get(md-1);
		if(sb1>=m){
			l=md+1;res=max(res,md);continue;
		}
		if(sb1+sb2>=m){
			l=md+1;res=max(res,md-1);continue;
		}
		r=md-2;
	}
	printf("%lld",res);
}