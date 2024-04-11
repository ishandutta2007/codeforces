#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int n=0,n1=0,n2=0,n3=0,n4=0,n5=0;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(n2==1 && n3==0 && s[i-1]=='u'){
			n2=0;
			n3=1;
			cout << '/';}
		if(s[i]=='r' && s[i+1]=='u' && n1==0 && n4==0){
			n1=1;
			n2=1;
			cout << '.';}
		if(n4==1)
			n4=0;
		cout << s[i];
		if(s[i]=='p' && n==0){
			n=1;
			n4=1;
			cout << "://";}
	}
}