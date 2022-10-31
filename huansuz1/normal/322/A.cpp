#include<iostream>

using namespace std;

int x,y;

int main(){
	cin>>x>>y;
	cout<<x+y-1<<endl;
	for (int i=1; i<=y; i++)
		cout<<1<< " " <<i<<endl;
	for (int i=2; i<=x; i++)
		cout<<i<<" "<<y<<endl;	


	return 0;
}