#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , N;
	for(cin >> T ; T ; --T){
		cin >> N;
		for(int i = 1 ; i <= N ; ++i){
			int a; cin >> a; a = abs(a); if(i & 1) a *= -1;
			cout << a << ' ';
		}
		cout << endl;
	}
	return 0;
}