#include "bits/stdc++.h"
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int bw = 1;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			char x;
			cin >> x;
			if (x == 'C' || x == 'M' || x == 'Y') bw = 0;
		}
	}
	if (bw){
		cout << "#Black&White";
	} else {
		cout << "#Color";
	}


	return 0;
}