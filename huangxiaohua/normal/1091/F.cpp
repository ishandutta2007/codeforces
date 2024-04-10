#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,gg,a1[100500];
ll a[100500],res,cur3,cur33,cur5,sb;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		char c=getchar();
		if(c=='W'){
			gg=1;
			cur33+=a[i];
			continue;
		}
		if(c=='G'){
			sb=min(cur33,a[i]);
			cur33-=sb;cur3+=sb;
			cur5+=a[i];
			continue;
		}
		if(c=='L'){
			if(cur33){
				sb=min(cur33,a[i]);
				res+=sb*4;
				cur33-=sb;a[i]-=sb;
			}
			if(cur3){
				sb=min(cur3,a[i]);
				res+=sb*4;
				cur3-=sb;a[i]-=sb;
			}
			if(cur5){
				sb=min(cur5,a[i]);
				res+=sb*6;
				cur5-=sb;a[i]-=sb;
			}
			if(gg){res+=a[i]*4;}
			else{res+=a[i]*6;}
			continue;
		}
		i--;
	}
	sb=min(cur3,cur5);
	res+=sb*4;
	cur3-=sb;cur5-=sb;
	res+=cur3*2;
	res+=cur33*2;
	res+=cur5*3;
	printf("%lld",res);
}