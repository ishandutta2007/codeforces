#include<iostream>
using namespace std;
int n,t0=0,t1=0,a[200009],h=100000,mx=0;string s;
void f(char x){
	if(x=='0') t0++;
	else t1++;}
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		f(s[i]);
		a[100000+t1-t0]=i;
		if(t0==t1)
			mx=i+1;}
	for(int i=1;i<n;i++){
		if(s[i-1]=='0') h--;
		else h++;
		if(a[h]!=0)
			mx=max(mx,a[h]-i+1);
	}
	cout<<mx;
}