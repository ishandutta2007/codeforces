#include<iostream>
#include<cmath> 

using namespace std;

	long long n,a,b,c;
	long long i; 

int work(long long m){
	for (i=a;i<=sqrt(m);i++){
		if ((m%i==0)&&(m>=i*b)){
			cout<<m<<endl;
			if (c==0){
				cout<<i<<' '<<m/i<<endl;
			}
			else{
				cout<<m/i<<' '<<i<<endl;
			}
			return 1;
			}
		}
	return 0;
}

int main(){
	cin>>n>>a>>b;
	if (a>b){
		c=a;
		a=b;
		b=c;
		c=1;
	}
	else{
		c=0;
	} 
	n=6*n;
	if (a*b>=n) {
		cout<<a*b<<endl;
		cout<<a<<' '<<b<<endl;
	}
	else{
		while (work(n)==0){
			n++; 
		}
	}
	return 0;
}