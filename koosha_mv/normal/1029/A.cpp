#include<iostream>
using namespace std;
int main(){
	int n,k,l=0,mx=0;string s,t1="";
	cin>>n>>k>>s;
	cout<<s;k--;
	for(int i=1;i<n;i++){
		l=0;
		for(int j=0;j<i;j++){
			if(s[j]!=s[n-i+j])
				l=1;
		}
		if(l==0)
			mx=i;
	}
	for(int i=mx;i<n;i++)
		t1+=s[i];
	for(int i=0;i<k;i++){
		cout<<t1;
	}
}