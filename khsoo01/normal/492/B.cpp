#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long i,n,l,a[1001];
double answer;
int main(){
	cin>>n>>l;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	std::sort(a,a+n);
	answer=std::max(2*(a[0]-0),2*(l-a[n-1]));
	for(i=1;i<n;i++){
		if(a[i]-a[i-1]>answer){
			answer=a[i]-a[i-1];
		}
	}
	answer=answer/2;
	printf("%.10lf",answer);
}