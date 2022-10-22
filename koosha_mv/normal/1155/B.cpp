#include<iostream>
using namespace std;
int main(){
	int n,t8,t=0,a=-1;string s;
	cin>>n>>s;
	t8=(n-11)/2+1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='8'){
			t++;
			if(t==t8){a=i;break;}}}
	if(a==-1 || a>n-11)cout<<"NO";
	else cout<<"YES";
}