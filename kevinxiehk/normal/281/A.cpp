#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	if(s[0]>='a')s[0]-=('a'-'A');
	cout<<s<<endl;
	return 0;
}