#include<iostream>
#include<algorithm>
using namespace std;
int saghf(long long n){
	if(n%2==0)
		return n/2;
	return (n/2)+1;
}
long long a[100000];
int main(){
	long long n,j=0,j2=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		j+=a[i];	
	}
	sort(a,a+n);
	for(long long i=0;i<saghf(n);i++){
		j2+=a[n-1-i];
	}
	//cout<<j<<" "<<j2<<endl;
	cout<<(j2*j2)+(j-j2)*(j-j2)<<endl;
}