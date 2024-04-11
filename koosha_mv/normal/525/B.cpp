#include<iostream>
using namespace std;
int sw[200099];
int main(){
	string s;cin>>s;
	int m,x,sum=0;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>x;
		sw[x-1]++;}
	for(int i=0;i<s.size()/2;i++){
		sum+=sw[i];
		if(sum%2==1){
			swap(s[i],s[s.size()-1-i]);}}
	cout<<s;
}