#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x=0,n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s[1]=='+')x++;
		else x--;
	}
	cout<<x<<endl;
	return 0;
}