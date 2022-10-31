#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,t;

ll n,m,tmp,m2,m3,tmp2;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		m=1;k=n%3;n=(n+2)/3;
		while(1){
			if(n<=m){m+=n-1;break;}
			n-=m;m*=4;
		}
		if(k==1){printf("%lld\n",m);continue;}
		tmp=1;n=m;m2=0;
		while(n){
			tmp2=n%4;
			if(tmp2==1){m2+=tmp*2;}
			if(tmp2==2){m2+=tmp*3;}
			if(tmp2==3){m2+=tmp*1;}
			n/=4;tmp*=4;
		}
		if(k==2){printf("%lld\n",m2);}
		else{printf("%lld\n",m^m2);}
	}
}