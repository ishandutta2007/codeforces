#include<bits/stdc++.h>
using namespace std;


int main(){
	int T , N , K1 , K2;
	for(cin >> T ; T ; --T){
		cin >> N >> K1 >> K2; bool f1 = 0;
		for(int i = 1 ; i <= K1 ; ++i){int a; cin >> a; f1 |= a == N;}
		for(int i = 1 ; i <= K2 ; ++i){int a; cin >> a;}
		puts(f1 ? "YES" : "NO");
	}
	return 0;
}