#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , N , mx , sum , A;
	for(cin >> T ; T ; --T){
		mx = sum = 0; cin >> N;
		for(int i = 1 ; i <= N ; ++i){cin >> A; mx = max(mx , A); sum += A;}
		if(mx > sum - mx) cout << "T" << endl;
		else if(mx == sum - mx) cout << "HL" << endl;
		else cout << (sum & 1 ? "T" : "HL") << endl;
	}
	return 0;
}