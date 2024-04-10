#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,st;
int t;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		if((a&1)+(b&1)+(c&1)+(d&1)<=1){
			cout<<"Yes"<<'\n';
		}
		else if(!a||!b||!c){
			cout<<"No"<<'\n';
		}
		else{
			if((a&1)+(b&1)+(c&1)+(d&1)>=3){
				cout<<"Yes"<<'\n';
			}
			else cout<<"No"<<'\n';
		}
	}
	return 0;
}