#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<char,int>lol;
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		for(char c='a';c<='z';c++)lol[c]=0;
		for(int j=0;j<s.length();j++)lol[s[j]]++;
		int x=0;
		bool cont=false;
		for(char c='a';c<='z';c++){
			if(lol[c]>1){
				cout<<"No"<<endl;
				cont=true;
			}	
			if(lol[c]==1)x++;
			if(x==s.length())break;
			if(x>=1&&lol[c]==0){
				cout<<"No"<<endl;
				cont=true;
			}
			if(cont)break;
		}
		if(!cont)cout<<"Yes"<<endl;
		
	}
}