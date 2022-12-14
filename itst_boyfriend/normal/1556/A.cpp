#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , a , b;
	for(cin >> T ; T ; --T){
		cin >> a >> b;
		if(a == 0 && b == 0) cout << 0 << endl;
		else if((a + b) % 2) cout << -1 << endl;
		else if(a != b) cout << 2 << endl;
		else cout << 1 << endl;
	}
	return 0;
}