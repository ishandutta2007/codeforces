#include<stdio.h>
#include<iostream>
using namespace std;
int n,now;
string s,t;
int main(){
	cin>>s,n=s.size(),t=s;
	now=1;
	for(int i=0;i<n;i++){
		if(now+96>=s[i])
			t[i]=now+96,now++;
		if(now>26)
			break;
	}
	if(now>26)
		cout<<t<<"\n";
	else puts("-1");
	return 0;
}