#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#define LL long long
using namespace std;
const int N=10000;
LL n,s,m,x;
int k;
int main(){
	cin>>n>>k>>s;m=n-1;
	if(k>s||m*k<s){
		printf("NO\n");return 0;
	}
	printf("YES\n");
	x=1;
	while(s){
		if((k-1)<=s-m){
			x=n+1-x;
			cout<<x<<" ";
			--k;s-=m;
		}
		else{
			LL t=s-k+1;
			if(x+t<=n){
				x=x+t;
				cout<<x<<" ";
				--k;s-=t;
			}
			else{
				x=x-t;
				cout<<x<<" ";
				--k;s-=t;
			}
		}
	}
	cout<<endl;
	return 0;
}
/*
*/