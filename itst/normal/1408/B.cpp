#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int T , N , K , A[103];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> K; int cnt = 0; A[0] = -1;
		for(int i = 1 ; i <= N ; ++i){cin >> A[i]; cnt += A[i]!= A[i - 1];}
		if(cnt == 1) cout << 1 << endl;
		else if(K == 1) cout << -1 << endl;
		else cout << (cnt - 1 + K - 2) / (K - 1) << endl;
	}
	return 0;
}