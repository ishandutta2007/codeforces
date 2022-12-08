#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int cic=100;
	int resp=0;
	for(int i=0;i<n;i++){
		int vqc,vcc;
		cin>>vqc>>vcc;
		if(vcc<cic){
			cic=vcc;
		}
		resp+=cic*vqc;
	}
	cout<<resp<<"\n";
	return 0;
}