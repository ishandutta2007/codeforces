#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j%2==1){
				cout<<n*(j+1)-i<<" ";
			}
			else{
				cout<<j*n+i+1<<" ";
			}
		}
		cout<<endl;
	}
}