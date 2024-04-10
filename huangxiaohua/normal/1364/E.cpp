#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,res[6666],x,y,sb,sb1,sb2,it;

int f(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&x);return x;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);

int main(){
	scanf("%d",&n);
	uniform_int_distribution<int>lim(1,n);
	x=1;y=2;sb=f(1,2);
	for(i=3;i<=n;i++){
		sb1=f(x,i);if(sb1>sb){continue;}
		sb2=f(y,i);
		if(sb1<sb&&sb1<sb2){y=i;sb=sb1;continue;}
		if(sb2<sb&&sb2<sb1){x=i;sb=sb2;continue;}
	}
	it=2047;
	for(i=1;i<=60;i++){
		k=lim(rng);
		if(k==x){i--;continue;}
		k=f(x,k);
		it&=k;
	}
	if(it){k=y;}
	else{k=x;}
	for(i=1;i<=n;i++){
		if(i==k){continue;}
		res[i]=f(i,k);
	}
	printf("! ");
	for(i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
}