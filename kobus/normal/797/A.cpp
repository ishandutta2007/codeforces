#include<bits/stdc++.h>
using namespace std;
int v[20];
int counter=0;
int maiordivisor(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			v[counter]=i;
			counter++;
			maiordivisor(n/i);
			return 0;
		}
	}
	v[counter]=n;
	return 0;
}
int main(){
	int n,k;
	cin>>n>>k;
	maiordivisor(n);
	int counter2=0;
	for(int i=0;i<20;i++){
		if(v[i]!=0){
			counter2++;
		}
	}
	if(counter2<k){
		cout<<"-1";
	}
	else{
		for(int i=0;i<k-1;i++){
			cout<<v[i]<<" ";
		}
		int w=v[k-1];
		for(int i=k;i<counter2;i++){
			w=w*v[i];
		}
		cout<<w;
	}
	cout<<"\n";
	return 0;
}