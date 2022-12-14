#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	long long K , tms = 1; cin >> K;
	string str = "codeforces"; int pot[10];
	for(int i = 0 ; i < 10 ; ++i) pot[i] = 1;
	int pos = 0;
	while(tms < K){
		tms = tms / pot[pos] * (pot[pos] + 1); ++pot[pos];
		pos = (pos + 1) % 10;
	}
	for(int i = 0 ; i < 10 ; ++i) cout << string(pot[i] , str[i]);
	return 0;
}