#include "bits/stdc++.h"
using namespace std;

int A[1000005], N;

int main(){
	cin >> N;
	for (int i=0; i<N; i++) cin >> A[i];
	sort(A, A+N);
	cout << A[(N-1)/2];



	return 0;
}