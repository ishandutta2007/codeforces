#include<bits/stdc++.h>
using namespace std;
int v[112345];
int main(){
	
	int n,k,premin=1123456789;
	cin>>n>>k;
	int mark=0;
	long long int resp=0;
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=0;i<n;i++){
		if(v[i]<premin){
			premin=v[i];
		}
	}
	for(int i=0;i<n;i++){
		if((v[i]-premin)%k==0){
			resp+=(v[i]-premin)/k;
		}
		else{
			mark=1;
		}
	}
	if(mark==1){
		cout<<"-1\n";
	}
	else{
		cout<<resp<<"\n";
	}
	return 0;
}