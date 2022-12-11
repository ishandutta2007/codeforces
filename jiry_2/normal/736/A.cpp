#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long n;
int main(){
	cin>>n;
	long long k1=0,k2=0;
	int ans=0;
	while (1){
		long long pre=k2; k2+=k1+1; k1=pre;
		if (k2>=n){
			printf("%d\n",ans); return 0;
		}
		ans++;
	}
}