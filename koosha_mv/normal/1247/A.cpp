#include<iostream>
using namespace std;
int main(){
	int x,y;cin>>x>>y;
	if(x==9 && y==1){
		cout<<9<<" "<<10;
		return 0;
	}
	if(y-x==1 || y-x==0)
		if(y-x==1)
			cout<<x<<" "<<y;
		else
			cout<<x*10<<" "<<y*10+1;
	else
		cout<<-1;
}