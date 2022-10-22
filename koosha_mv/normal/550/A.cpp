#include<iostream>
using namespace std;
int main(){
		string s; 
		cin>>s;
		if(s.find("AB")!=-1 && s.find("BA",s.find("AB")+2)!=-1 || s.find("BA")!=-1 && s.find("AB",s.find("BA")+2)!=-1)
			cout<<"YES";
		else cout<<"NO";
}