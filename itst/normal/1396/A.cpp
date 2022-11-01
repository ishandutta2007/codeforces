#include<bits/stdc++.h>
using namespace std;

long long N , A[100003];

int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	cout << "1 1\n" << (N - A[1]) << endl; A[1] = N;
	if(N == 1) cout << "1 1\n0\n";
	else{
		cout << "2 " << N << endl;
		for(int i = 2 ; i <= N ; ++i){
			cout << (N - 1ll) * A[i] << ' ';
			A[i] = N * A[i];
		}
		cout << endl;
	}
	cout <<  1 << ' ' << N << endl;
	for(int i = 1 ; i <= N ; ++i) cout << -A[i] << ' ';
	return 0;
}