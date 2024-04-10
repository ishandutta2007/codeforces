#include<bits/stdc++.h>
using namespace std;

int T , N , A[30003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <=N ;++i) cin >> A[i];
		int pl = A[1] , pr = 0; bool f = 1;
		for(int i = 2 ; i <= N ; ++i){
			if(A[i] < pr) f = 0;
			if(A[i] - pr < pl) pl = A[i] - pr;
			else pr += A[i] - pr - pl;
		}
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}