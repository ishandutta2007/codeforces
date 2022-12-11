#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
map<long long ,long long>A,B;
long long n,l,r;
void solve(long long n){
	if (A.count(n)) return;
	if (n==1){
		A[n]=1,B[n]=1; return;
	}
	if (n==0){
		A[n]=1; B[n]=0; return;
	}
	solve(n/2);
	A[n]=A[n/2]*2+1;
	B[n]=B[n/2]*2+(n%2);
}
long long solve(long long n,long long r){
	if (r==0) return 0;
	if (n==1) return 1;
	if (n==0) return 0;
	long long k1=n/2,k2=A[k1];
	if (k2>=r) return solve(n/2,r);
	long long ans=B[k1]+(n%2);
	return ans+solve(n/2,r-k2-1);
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&l,&r);
	solve(n);
	printf("%I64d\n",solve(n,r)-solve(n,l-1));
	return 0;
}