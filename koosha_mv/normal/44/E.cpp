#include<iostream>
using namespace std;
int n,a,b,t;string s;
int dp(int x,int l){
	if(x==s.size())
		return 0;
	t=(s.size()-x)/l;
	for(int i=x;i<x+t;i++){
		cout<<s[i];}
	cout<<endl;
	dp(x+t,l-1);}
int main(){
	cin>>n>>a>>b>>s;
	if(float(s.size())/float(n)<a || float(s.size())/float(n)>b){
		cout<<"No solution";
		return 0;}
	dp(0,n);
}