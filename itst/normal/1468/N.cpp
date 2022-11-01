#include<bits/stdc++.h>
using namespace std;

int main(){
	int T; vector < int > C(3);
	for(cin >> T ; T ; --T){
		bool flg = 1; for(int i = 0 ; i < 3 ; ++i) cin >> C[i];
		for(int i = 0 ; i < 3 ; ++i){int x; cin >> x; C[i] -= x; flg &= C[i] >= 0;}
		int P , Q; cin >> P >> Q; P = max(P - C[0] , 0); Q = max(Q - C[1] , 0); flg &= P + Q <= C[2];
		cout << (flg ? "YES" : "NO") << endl;
	}
	return 0;
}