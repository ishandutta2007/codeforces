#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,a,b,x,t=0,p;
	cin>>n>>a>>b;
	int mar=0;
	x=n;
	while(x%2==0){
		mar++;
		x/=2;
	}
	n/=2;
	p=n/2;
	while(1){
		if((a>n && b<=n)||(a<=n && b>n)){if(t==0)
				cout<<"Final!";
			else cout<<mar-t;
			break;
		}
		else{
			if(a>n && b>n){
				n+=p;
				p=p/2;
				}
			else{
				n-=p;
				p/=2;
				}
		}
		t++;}}