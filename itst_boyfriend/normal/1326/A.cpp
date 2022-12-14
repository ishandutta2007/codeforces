#include<bits/stdc++.h>
using namespace std;

signed main(){
	int T;
	for(cin >> T ; T ; --T){
		int N; cin >> N;
		if(N == 1) puts("-1");
		else{cout << 2; while(--N) cout << 3; cout << endl;}
	}
	return 0;
}