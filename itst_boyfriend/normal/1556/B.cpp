#include<bits/stdc++.h>
using namespace std;

int A[100003] , T , C[2] , N;

long long calc(int x){
	if(C[x] - C[!x] < 0) return 1e18;
	deque < int > lft[2] , more[2]; long long sum = 0;
	for(int i = 1 ; i <= N ; ++i){
		if(lft[A[i]].size()){sum += i - lft[A[i]].front(); lft[A[i]].pop_front();}
		else more[A[i]].push_back(i);
		if(more[x ^ ((i - 1) & 1)].size()) more[x ^ ((i - 1) & 1)].pop_back();
		else lft[x ^ ((i - 1) & 1)].push_back(i);
	}
	return sum;
}

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; C[0] = C[1] = 0;
		for(int i = 1 ; i <= N ; ++i){cin >> A[i]; A[i] = A[i] & 1; ++C[A[i]];}
		if(abs(C[0] - C[1]) > 1) cout << -1 << endl;
		else cout << min(calc(0) , calc(1)) << endl;
	}
	return 0;
}