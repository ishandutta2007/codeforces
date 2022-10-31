#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,x,y;

int main(){
	scanf("%d",&n);
	x=1;y=2;
	while(x<=n||y<=n){
		if(x==n||y==n){puts("1");return 0;}
		if(x&1){x=y*2;y=y*2+1;}
		else{x=y*2-1;y=y*2;}
	}
	puts("0");
}