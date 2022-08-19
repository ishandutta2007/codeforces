#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

bool match(int x, int y){
	if(x == 3 && y == 3) return 1;
	if(x == 4 && y == 6) return 1;
	if(x == 5 && y == 9) return 1;
	if(x == 6 && y == 4) return 1;
	if(x == 7 && y == 7) return 1;
	if(x == 8 && y == 0) return 1;
	if(x == 9 && y == 5) return 1;
	if(x == 0 && y == 8) return 1;
	return 0;
}

string s;

int main(){
	cin >> s;
	if(s.size() == 1){
		if(s[0] == '1' || s[0] == '2' || s[0] == '3' || s[0] == '7'){
			cout << "Yes";
			return 0;
		}
	}
	for(int i=0; i<=s.size()-i-1; i++){
		if(!match(s[i] - '0', s[s.size()-1-i] - '0')){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}