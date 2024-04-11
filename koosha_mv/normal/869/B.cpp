#include<iostream>
using namespace std;
unsigned long long int a,b,j=1;
int main(){
	cin>>a>>b;
	a++;
	if(a/10 !=b/10){
		cout<<0;return 0;
	}
	else{
		for(int i=a%10;i<=b%10;i++){
			j*=i;
		}
		cout<<j%10;
	}
}