#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , A , B , C;
	for(cin >> T ; T ; --T){
		cin >> A >> B >> C;
		if(B == 0)
			if(A) cout << string(A + 1 , '0') << endl;
			else cout << string(C + 1 , '1') << endl;
		else{
			cout << string(A + 1 , '0') << string(C + 1 , '1'); --B;
			int cur = 1; while(B--) cout << (cur ^= 1);
			cout << endl;
		}
	}
	return 0;
}