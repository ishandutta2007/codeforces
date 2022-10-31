#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

char s[205];

int main(){
	cin>>n>>s+1;
	for(i=1;i<=n;i++){
		if(s[i]=='x'){m++;}
		else{m--;}
	}
	m/=2;
	cout<<abs(m)<<endl;
	for(i=1;i<=n;i++){
		if(m<0){
			if(s[i]=='X'){s[i]='x';m++;}
		}
		else{
			if(m>0){
				if(s[i]=='x'){s[i]='X';m--;}
			}
		}
		cout<<s[i];
	}
}