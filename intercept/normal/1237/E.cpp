#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=1e6+9;
int n;
int dp[M][2],dep[M];
int main(){
	cin>>n;
	if(n<=2){
		puts("1");
		return 0;
	}
	int l=1,r=2;
	while(1){
		if(r&1)l=r*2-1,r=r*2;
		else l=r*2,r=l+1;
		if(n==l||n==r){
			puts("1");
			return 0;
		}
		if(l>n){
			puts("0");
			return 0;
		}
	}
	return 0;
}