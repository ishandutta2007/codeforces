#include<iostream>
using namespace std;
int t(int x,int y){
	if((y-x)%2==0){
		if(x%2==1)return (-1*((y-x)/2))-x;
		return (((y-x)/2)+x);}
	if(x%2==0)return -1*((y-x+1)/2);return ((y-x+1)/2);}
int main(){
	int q,l,r;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>l>>r;
		//t(l,r);
		cout<<t(l,r)<<endl;}}