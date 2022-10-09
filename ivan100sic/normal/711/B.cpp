#include "bits/stdc++.h"
using namespace std;

int N;
long long A[505][505], s, t;
int x, y;

int main(){
	cin >> N;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			cin >> A[i][j];
			if (A[i][j] == 0){
				x = i;
				y = j;
			}
		}
	}
	
	if (N == 1){
		cout << 1 << endl;
		return 0;
	}
	
	int r = x == 1 ? 2 : 1;
	for (int j=1; j<=N; j++){
		s += A[r][j] - A[x][j];
		t += A[r][j];
	}
	
	A[x][y] = s;
	
	// check
	for (int i=1; i<=N; i++){
		long long q = 0;
		for (int j=1; j<=N; j++) q += A[i][j];
		if (q != t) s = -1;
	}
	
	for (int i=1; i<=N; i++){
		long long q = 0;
		for (int j=1; j<=N; j++) q += A[j][i];
		if (q != t) s = -1;
	}

	long long q = 0;
	for (int j=1; j<=N; j++) q += A[j][j];
	if (q != t) s = -1;
	
	q = 0;
	for (int j=1; j<=N; j++) q += A[j][N-j+1];
	if (q != t) s = -1;
	
	if (s <= 0) s = -1;
	
	cout << s << endl;

	return 0;
}