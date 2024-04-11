#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll t=0,n,k,l=0;
string x;
string s1;
string jam(string s,int y){
	if(s[y]=='9'){
		if(y==0){l=1;return 0;}
		s[y]='0';
		return jam(s,y-1);
	}
	s[y]=char(s[y]+1);
	return s;
}
int main(){
	cin>>n>>k;
	cin>>x;
	f(i,0,n){
		if(x[i]>x[i%k]){l=-1;break;}
		if(x[i]<x[i%k]) break;
	}
	if(l==0){
		cout<<n<<endl;
		f(i,0,n) cout<<x[i%k];
		return 0;
	}
	l=0;
	f(i,0,k){
		s1+=x[i];
	}
	s1=jam(s1,k-1);
	cout<<n<<endl;
	f(i,0,n) cout<<s1[i%k];
}