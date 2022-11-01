#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , L; string S;
	for(cin >> T ; T ; --T){
		cin >> L >> S; bool f1 = 1 , f2 = 1;
		for(int i = 0 ; i < L ; ++i){
			f1 &= S[i] != '<'; f2 &= S[i] != '>';
		}
		if(f1 || f2){cout << L << endl;}
		else{
			int cnt = L;
			for(int i = 0 ; i < S.size() ; ++i)
				cnt -= S[i] != '-' && S[(i + 1) % L] != '-';
			cout << cnt << endl;
		}
	}
	return 0;
}