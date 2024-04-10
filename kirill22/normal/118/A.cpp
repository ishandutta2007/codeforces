#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	ll n,m,k,ans=0;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		char t=tolower(s[i]);
		if (t=='a' || t=='e' || t=='y' || t=='u' || t=='o' || t=='i'){
			continue;
		}
		else{
			cout << "." << t;
		}
	}
	
	
	return 0;
}