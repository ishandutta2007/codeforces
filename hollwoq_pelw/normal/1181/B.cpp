#include<bits/stdc++.h>
using namespace std;
typedef string big;
int n;
big sum(big x,big y){
	if(x.size()<y.size()) swap(x,y);
	for(int i=0; i<y.size() ;i++) x[x.size()-y.size()+i]+=y[i]-48;
	for(int i=x.size()-1; i>=1 ;i--){
		if(x[i]>'9'){
			x[i]-=10;
			x[i-1]++;
		}
	}
	if(x[0]>'9'){
		x[0]-=10;
		x='1'+x;
	}
	return x;
}
big mini(big x,big y){
	if(x.size()<y.size()) return x;
	if(x.size()>y.size()) return y;
	for(int i=0; i<x.size() ;i++){
		if(x[i]<y[i]) return x;
		if(x[i]>y[i]) return y;
	}
	return x;
}
string s,t;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s;
	t=s;
	int mid=n/2;
	while(s[mid]=='0') mid--;
	if(mid!=0) t=mini(t,sum(s.substr(0,mid),s.substr(mid)));
	mid=(n+1)/2; 
	while(mid<n && s[mid]=='0') mid++;
	if(mid!=n) t=mini(t,sum(s.substr(0,mid),s.substr(mid)));
	cout << t << '\n';
}