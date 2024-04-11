#include<iostream>
using namespace std;
int main(){
	int n,b=0,q=0,w=0,t=0,mn=0;string s;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		w--;
		if(s[i]=='('){
			w+=2;
		}
		mn=min(mn,w);
	}
	if(mn>=-1 && !w)
		cout<<"YES";
	else
		cout<<"NO";
}