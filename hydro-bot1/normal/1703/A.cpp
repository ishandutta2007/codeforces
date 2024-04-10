// Hydro submission #62f219b73f8efa55416cc150@1660033464124
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	string str;
	for(int j=n;j>=1;j--){
		cin>>str;
		for(int i=0;i<str.size();i++){
		 	str[i]=tolower(str[i]);
		 //	cout<<str;
		}
		if(str=="yes"){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}