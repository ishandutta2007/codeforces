#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	ll n,m,k;
	cin >> n;
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		if (s.size()>10){
			cout << s[0] << s.size()-2 << s[s.size()-1] << endl;
		}
		else{
			cout << s << endl;
		}
	}
	return 0;
}