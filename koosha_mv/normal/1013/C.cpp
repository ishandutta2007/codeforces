#include<iostream>
#include<algorithm>
using namespace std;
long long a[200099],mn=0;
int main(){
	long long n;cin>>n;
	for(long long i=0;i<n*2;i++) cin>>a[i];
	sort(a,a+n*2);
	mn=(a[n-1]-a[0])*(a[n*2-1]-a[n]);
	for(long long i=1;i+n<=n*2-1;i++){
		mn=min(mn,(a[2*n-1]-a[0])*(a[i+n-1]-a[i]));
	}
	cout<<mn;
}