#include<iostream>
#define ll long long
using namespace std;
int i,j,k,n,m;
int x,y,z;
int main(){
	cin>>x>>y>>z;
	for(i=200;i>=0;i--)
		if(i<=x && i+1<=y && i+2<=z){
			cout<<i*3+3<<endl;
			return 0;
		}
	return 0;
}