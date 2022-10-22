#include<bits/stdc++.h>
using namespace std;
long long n,x;
long long sum[2];
int main(){
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x;
		sum[i&1]+=x/2;
		sum[(i+1)&1]+=x-x/2;
	}
	cout<<min(sum[0],sum[1]);
	return 0;
}