#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int main(){
	int T;
	for(cin >> T ; T ; --T){
		int N; cin >> N; cout << (N + 1) / 10 << endl;
	}
	return 0;
}