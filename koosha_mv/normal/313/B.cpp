#include<iostream>
using namespace std;
string s;int n,x,y,f[100009];
int main(){
	cin>>s>>n;
	for(int i=1;i<s.size();i++){
		f[i]=f[i-1];
		if(s[i-1]==s[i])
			f[i]++;}
	while(n--){
		cin>>x>>y;
		cout<<f[y-1]-f[x-1]<<endl;}
}