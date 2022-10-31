#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,sb,lst;

string l,r;

void NMSL(){
	for(int i=1;i<=300;i++){
		cout<<"b";
	}
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cout<<"a"<<endl;
	cin>>x;
	
	if(x==300){
		NMSL();
	}
	
	if(!x)return 0;
	n=x+1;
	
	
	
	for(i=1;i<=n;i++)cout<<"a";
	cout<<endl;
	cin>>k;
	if(!k)return 0;
	
	if(k==n){
		for(i=1;i<=n-1;i++)cout<<"b";
		return 0;
	}
	
	for(i=1;i<=n-k;i++)l+="a";
	
	lst=k;
	
	for(t=n;t>=1;t--){
		cout<<l<<'b'<<r<<endl;
		cin>>k;
		if(!k)return 0;
		if(k<lst){
			r="b"+r;
			lst=k;
		}
		else{
			r="a"+r;
			l.pop_back();
		}
	}
	
	return 1;
}