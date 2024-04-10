#include<iostream>

using namespace std;

int main(){
	long n,m,a,b,ans;
	cin>>n>>m>>a>>b;
	ans=a*n;
	if (ans>(n/m)*b+(n%m)*a){
		ans=(n/m)*b+(n%m)*a; 
	} 
	if (ans>((n-1)/m+1)*b){
		ans=((n-1)/m+1)*b;
	}
	cout<<ans<<endl;
	return 0;
}