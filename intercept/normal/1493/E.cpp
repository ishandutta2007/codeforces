#include<bits/stdc++.h>
using namespace std;
int n;
string l,r;
string solve(){
	if(r[0]=='0')return "0";
	if(l[0]=='0')return string(n,'1');
	if(r[n-1]=='1')return r;
	for(int i=n-1;i>=0;--i){
		if(l[i]=='1')l[i]='0';
		else {l[i]='1';break;}
	}
	r[n-1]=l<r?'1':'0';
	return r;
}
int main(){
	cin>>n>>l>>r;
	cout<<solve()<<endl;
	return 0;
}