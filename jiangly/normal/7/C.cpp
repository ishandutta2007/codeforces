//Time Complexity : O(log(int))
//Space Complexity : O(log(int))
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ExGcd(int a,int b,ll&x,ll&y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		int g=ExGcd(b,a%b,y,x);
		y=y-a/b*x;
		return g;
	}
}
int main(){
	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	ll x,y;
	int g=ExGcd(A,B,x,y);
	if(C%g!=0){
		printf("-1\n");
	}else{
		x=-C/g*x;
		y=-C/g*y;
		printf("%I64d %I64d\n",x,y);
	}
	return 0;
}