#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;
int m,n,sum,x;
string s,l,t="0123456789";

int main(){
	cin>>n>>m;
	if (n==1 && m==0) {cout<<"0 0"; return 0;}
	if (m==0 || (n*9<m)) {cout<<"-1 -1"; return 0;}
	s='1';
	l='9';
	for (int i=1; i<n; i++){
		s+='0';
		l+='9';
	}
	x=s.length()-1;
	for (int i=0; i<s.length(); i++)
		sum+=(s[i]-'0');
	while(sum!=m){
		sum=0;
		if (s[x]-'0'==9) x--; 
		s[x]=t[s[x]-'0'+1];
		for (int i=0; i<s.length(); i++)
			sum+=(s[i]-'0');
	}
	sum=0;
	x=l.length()-1;
	for (int i=0; i<l.length(); i++)
		sum+=(l[i]-'0');
	while(sum!=m){
		sum=0;
		if (l[x]-'0'==0) x--; 
		l[x]=t[l[x]-'0'-1];
		for (int i=0; i<l.length(); i++)
			sum+=(l[i]-'0');
	}
	cout<<s<<" "<<l;


}