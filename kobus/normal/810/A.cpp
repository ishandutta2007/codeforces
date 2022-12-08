#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	double somanotas=0;
	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		somanotas+=y;
	}
	int resp=0;
	while((1.0*somanotas/n)<1.0*k-0.5){
		somanotas+=k;
		n++;
		resp++;
	}
	cout<<resp<<"\n";
	
	return 0;
}