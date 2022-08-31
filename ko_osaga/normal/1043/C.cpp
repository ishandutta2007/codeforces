#include <bits/stdc++.h>
using namespace std;

string s;
int chk[1005];

int main(){
	cin >> s;
	s.push_back('z');
	for(int i=0; i+1<s.size(); i++){
		if(s[i] == 'a' && s[i+1] != 'a'){
			chk[i] = 1;
			reverse(s.begin(), s.begin() + i + 1);
		}
		else if(s[i] == 'b' && s[i+1] != 'b'){
			chk[i] = 1;
			reverse(s.begin(), s.begin() + i + 1);
		}
	}
	s.pop_back();
	if(s.back() == 'a'){
		chk[s.size()-1] = 0;
		reverse(s.begin(), s.end());
	}
	assert(is_sorted(s.begin(), s.end()));
	for(int i=0; i<s.size(); i++) printf("%d ", chk[i]);
}