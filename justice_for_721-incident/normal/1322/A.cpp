#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin >> n;
	string s;
	cin >> s;
	int mx=0;
	int t=0;
	int g=0;
	for(auto c:s){
		if(c=='(') t++;
		else t--;
		if(t<0) g++;
		if(t==0 && c=='(') g++;
	}
	if(t!=0) cout << "-1\n";
	else cout << g << endl;
}