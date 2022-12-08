#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;


int toint(string a){
	if(a.length()==0){
		return 0;
	}
	string b;
	for(int i=0;i<a.length()-1;i++){
		b+=a[i];
	}
	return a[a.length()-1]-'0'+10*toint(b);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;
	string b;
	for(int i=0;i<a.length();i++){
		if(i==0){
			b+=(((int)a[i])+1);
		}
		else{
			b+='0';
		}
	}
	cout<<toint(b)-toint(a)<<"\n";
	
	return 0;
}