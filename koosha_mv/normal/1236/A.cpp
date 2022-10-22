#include<iostream>
using namespace std;
int t(int x,int y,int z){
	int t=0;
	z=z/2;
	t+=(min(y,z)*3);
	y-=min(y,z);
	y=y/2;
	t+=min(x,y)*3;
	return t;
}
int main(){
	int q,x,y,z;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>x>>y>>z;
		cout<<t(x,y,z)<<endl;
	}
}