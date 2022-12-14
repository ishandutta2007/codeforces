#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int main(){
	int T; string s; int L;
	for(cin >> T ; T ; --T){
		cin >> L >> s; string temp = s; sort(temp.begin() , temp.end()); int cnt = 0;
		for(int i = 0 ; i < L ; ++i) cnt += temp[i] != s[i];
		cout <<cnt << endl;
	}
	return 0;
}