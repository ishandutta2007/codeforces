#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,t,tt;
	int min=999999999,minindex=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>t>>tt;
		while(t<b)t+=tt;
		if(min>t){
			min=t;
			minindex=i;
		}
	}
	cout<<minindex<<endl;
	return 0;
}