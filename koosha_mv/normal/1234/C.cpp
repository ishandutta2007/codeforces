#include<iostream>
using namespace std;
string s1,s2;
string f(int x,int y,int n){
	if(x==n){
		if(y==1){
			if(int(s2[x])>'2')
				return"NO";
			return"YES";
		}
		if(int(s2[x])>'2' && int(s1[x])>'2')
			return "YES";
		return"NO";
	}
	if(y==0){
		if(s1[x]<='2')
			return (f(x+1,y,n));
		else{
			if(s2[x]<='2')
				return"NO";
			return(f(x+1,1,n));
		}
	}
	else{
		if(s2[x]<='2')
			return(f(x+1,y,n));
		if(s1[x]<='2')
			return"NO";
		return(f(x+1,0,n));
	}
}
int main(){
	int q,n;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>n;cin>>s1>>s2;
		cout<<(f(0,0,n-1))<<endl;
	}
}