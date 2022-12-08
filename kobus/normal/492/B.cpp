
#include<bits/stdc++.h>

using namespace std;
int v[1003];
int main(){
	int n,l;
	cin>>n>>l;
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	sort (v,v+n);
	int dimax=0;
	for (int i=0;i<n-1;i++){
		if(abs(v[i+1]-v[i])>dimax){
			dimax=abs(v[i]-v[i+1]);
		}
	}
	int resp=max(dimax,2*max(v[0],l-v[n-1]));
	if(resp%2==0){
		cout<<resp/2<<".000000000"<<"\n";
	}
	else{
		cout<<resp/2<<".500000000"<<"\n";
	}
	return 0;
}