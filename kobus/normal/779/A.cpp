#include<bits/stdc++.h>
using namespace std;
int m[3][6]={0};
int main(){
	int n;
	cin>>n;
	int resp=0;
	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		m[1][y]++;
	}
	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		m[2][y]++;
	}
	for(int i=1;i<=5;i++){
		if((m[1][i]+m[2][i])%2==1){
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i=1;i<=5;i++){
		resp+=(abs(m[1][i]-m[2][i]))/2;
	}
	cout<<resp/2<<"\n";
	return 0;
}