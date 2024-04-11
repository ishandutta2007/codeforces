#include<iostream>
using namespace std;
long long mx=0,x,r[1009],l[1009],e=1e9+7,h,w,jv=1;
int main(){
	cin>>h>>w;
	for(int i=0;i<h;i++){
		cin>>r[i];}
	for(int i=0;i<w;i++){
		cin>>l[i];
		if(r[l[i]]>i){
			//cout<<"A"<<i<<" "<<l[i]+1;
			cout<<0;
			return 0;}}
	for(int i=0;i<h;i++){
		if(l[r[i]]>i){
			//cout<<"b"<<i;
			cout<<0;
			return 0;}}
	for(int i=0;i<w;i++){
		x=l[i];
		for(int j=x+1;j<h;j++){
			if(r[j]<=i-1)
				jv*=2,jv=jv%e;}}
	cout<<jv;
}