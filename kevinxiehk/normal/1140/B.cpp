#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>s;
		if(n==1){
			cout<<"0"<<endl;
			continue;
		}
		int l=0,r=0;
		while(s[l]!='>')l++; 
		while(s[s.length()-1-r]!='<')r++;
		cout<<min(l,r)<<endl;
	}
	return 0;
}