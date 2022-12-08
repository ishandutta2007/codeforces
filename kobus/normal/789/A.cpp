#include <iostream>
using namespace std;

int V[112345];

int main(){

	int n,k,rp=0;
	cin>>n>>k;

	for (int q=0;q<n;q++){
		cin>>V[q];
	}
	for (int q=0;q<n;q++){
		if (V[q]%k==0){
			rp+=V[q]/k;
		}
		if (V[q]%k!=0){
			rp+=((V[q]-(V[q]%k))/k)+1;
		}
	}
	if (rp%2==0){
		cout<<rp/2<<"\n";
	}
	if (rp%2==1){
		cout<<(rp+1)/2<<"\n";
	}

	return 0;
}