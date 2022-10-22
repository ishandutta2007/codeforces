#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
long long n[10009];
ll gcd(ll x,ll y){
	return !y?x:gcd(y,x%y);
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++)scanf("%lld",&n[i]);
	for(int i=1;i<=t;i++){
		for(int k=0;k<=2;k++){
			int sum=0;
			for(int j=18;j>=0;j--)sum+=(n[i]/(long long)pow(10ll,18-j))%10;
			if(gcd(n[i],sum)>1){printf("%lld\n",n[i]);break;}
			n[i]++;
		}
	}
	return 0;
}