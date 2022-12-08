#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		if(i%4==0 || i%4==1){
			cout<<"a";
		}
		else{
			cout<<"b";
		}
	}
	cout<<"\n";
	return 0;
}