#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,x,y=1023;
int AND=1023,OR,XOR;

int main() {
	cin.tie(0);
	cin>>t;
	while(t--){
		string s;
		cin>>s>>k;
		if(s[0]=='|'){
			x|=k;y|=k;
		}
		if(s[0]=='&'){
			x&=k;y&=k;
		}
		if(s[0]=='^'){
			x^=k;y^=k;
		}
	}
	for(i=1;i<=10;i++){
		if((x&b(i))&&(y&b(i))){
			OR|=b(i);
		}
		if(!(x&b(i))&&(y&b(i))){
			continue;
		}
		if(!(x&b(i))&&!(y&b(i))){
			AND^=b(i);
		}
		if((x&b(i))&&!(y&b(i))){
			XOR^=b(i);
		}
	}
	cout<<3<<endl;
	cout<<"& "<<AND<<endl;
	cout<<"| "<<OR<<endl;
	cout<<"^ "<<XOR<<endl;
}