#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
pii bullcow(string a, string b){
	int bull = 0, cow = 0, n = 4, matches = 0; set<char> A, B;
	for(int i = 0;i < n; i++){
		if(a[i] == b[i]) bull ++;
		A.insert(a[i]); B.insert(b[i]);
	}
	for(char c: A) if(B.count(c)) matches ++;
	return mp(bull, matches - bull);
}
string s;
int main(){
	int bull, cow;
	for(int i = 0; i < 10; i++){
		string c;
		char _c = (char)('0' + i);
		c += _c;
		c += c + c + c;
		cout << c << endl;
		fflush(stdout);
		cin >> bull >> cow;
		if(bull + cow) s += _c;
	}

	do{
		cout << s << endl; fflush(stdout);
		cin >> bull >> cow;
		if(bull == 4){
			return 0;
		}
	}
	while(next_permutation(s.begin(), s.end()));
}