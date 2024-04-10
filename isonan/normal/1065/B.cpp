#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long n,m;
int main(){
	cin>>n>>m;
	cout<<max(n-(m<<1),0ll)<<' ';
	for(long long i=0;i<=n;i++){
		if((i*(i-1))>>1>=m){
			cout<<n-i;
			return 0;
		}
	}
}