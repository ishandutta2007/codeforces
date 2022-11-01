#include<bits/stdc++.h>
using namespace std;

int T , N , A[200003]; long long V0 , V1;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		sort(A + 1 , A + N + 1); V0 = V1 = 0;
		for(int i = N ; i ; --i)
			if((N - i + 1) % 2 && !(A[i] % 2)) V0 += A[i];
			else if(!((N - i + 1) % 2) && A[i] % 2) V1 += A[i];
		cout << (V0 > V1 ? "Alice" : (V0 == V1 ? "Tie" : "Bob")) << endl;
	}
	return 0;
}