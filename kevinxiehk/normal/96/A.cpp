#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int cnt=1;
	cin>>s;
	for(int i=1;i<s.length();i++){
		if(s[i]==s[i-1])cnt++;
		else cnt=1;
		if(cnt==7){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}