#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

string s;
char r[2][1111];

int main(){
	cin >> s;
	for(int i=0; i<26; i++){
		if(s[i] == s[i+1]){
			puts("Impossible");
			return 0;
		}
	}
	int st, ed;
	for(int i=0; i<27; i++){
		for(int j=0; j<i; j++){
			if(s[i] == s[j]){
				st = j;
				ed = i;
				break;
			}
		}
	}
	s.erase(s.begin() + ed);
	if(st == 0 && ed == 26){
		for(int i=0; i<13; i++) putchar(s[i]);
		puts("");
		for(int i=0; i<13; i++) putchar(s[25-i]);
		return 0;
	}
	int dis = (ed - st + 1) / 2;
	rotate(s.begin(), s.begin() + st, s.end());
	for(int i=0; i<dis; i++){
		r[0][13-dis+i] = s[i];
	}
	for(int i=dis; i<13+dis; i++){
		r[1][12-(i-dis)] = s[i];
	}
	for(int i=13+dis; i<26; i++){
		r[0][i-13-dis] = s[i];
	}
	cout << r[0] << endl << r[1] << endl;
}