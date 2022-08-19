#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

string s;
int chk[1000005];

int main(){
	int n; cin >> n;
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '>') break;
		chk[i] = 1;
	}
	for(int i=s.size()-1; i>=0; i--){
		if(s[i] == '<') break;
		chk[i] = 1;
	}
	cout << count(chk, chk + s.size(), 1) << endl;
}