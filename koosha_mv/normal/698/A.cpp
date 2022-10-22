#include<iostream>
using namespace std;
int a[109],dp0[109],dp1[109],dp2[109];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];}
	for(int i=0;i<n;i++){
		dp0[i+2]=max(max(dp0[i+1],dp1[i+1]),dp2[i+1]);
		if(a[i]==1 || a[i]==3){
			dp1[i+2]=max(dp0[i+1],dp2[i+1])+1;
		}
		if(a[i]==2 || a[i]==3){
			dp2[i+2]=max(dp1[i+1],dp0[i+1])+1;
		}
	}
	cout<<n-max(max(dp0[n+1],dp1[n+1]),dp2[n+1]);
}