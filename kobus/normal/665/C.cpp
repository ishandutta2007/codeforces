#include<bits/stdc++.h>
using namespace std;
char v[212345];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	
	for(int i=0;i<s.length();i++){
		v[i]=s[i];
	}
	cout<<v[0];
	for(int i=1;i<s.length();i++){
		if(v[i]==v[i-1]){
			if(!(v[i-1]=='z' || v[i+1]=='z')){
				v[i]='z';
			}
			else if (!(v[i-1]=='y' || v[i+1]=='y')){
				v[i]='y';
			}
			else{
				v[i]='x';
			}
		}
		cout<<v[i];
	}
	cout<<"\n";
	return 0;
}