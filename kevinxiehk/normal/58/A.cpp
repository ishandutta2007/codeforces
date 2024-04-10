#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	char c[6]{'a','h','e','l','l','o'};
	int a=1;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]==c[a])a++;
		if(a==6){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}