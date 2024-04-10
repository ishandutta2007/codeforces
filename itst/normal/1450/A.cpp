#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int main(){
	int T;
	for(cin >> T ; T ; --T){
		int L; string s; cin >> L >> s;
		sort(s.begin() , s.end()); cout << s << endl;
	}
	return 0;
}