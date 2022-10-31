#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t;
string s,l,r;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>l>>r;
	if(l[0]!=r[0]){
		for(i=1;i<=n;i++){cout<<1;}return 0;
	}
	if(l==r){cout<<r;return 0;}
	if(r[n-1]=='1'){cout<<r;return 0;}
	l[n-1]++;
	for(i=n-1;i>=1;i--){
		if(l[i]>'1'){l[i]-=2;l[i-1]++;}
	}
	if(r==l){cout<<r;return 0;}
	r[n-1]='1';
	cout<<r;
}