#include<bits/stdc++.h>
using namespace std;
long long n,a[100003],H,A,R,D;string s;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		if(s[i]=='h')H+=a[i];
		if(s[i]=='a')A=min(H,a[i]+A);
		if(s[i]=='r')R=min(A,a[i]+R);
		if(s[i]=='d')D=min(R,a[i]+D);
	}
	cout<<D;
}