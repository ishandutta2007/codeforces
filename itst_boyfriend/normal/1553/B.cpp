#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int main(){
	int Q; string s , t;
	for(cin >> Q ; Q ; --Q){
		cin >> s >> t; bool flg = 0;
		for(int i = 0 ; i < s.size() ; ++i){
			int pos = 0;
			for(int j = i ; j < s.size() && pos < t.size() && s[j] == t[pos] ; ++j){
				++pos; int temp = pos;
				for(int k = j - 1 ; k >= 0 && temp < t.size() && s[k] == t[temp] ; --k , ++temp);
				flg |= temp == t.size();
			}
		}
		puts(flg ? "YES" : "NO");
	}
	return 0;
}