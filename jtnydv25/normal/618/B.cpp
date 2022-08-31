#include <bits/stdc++.h>
using namespace std;

int A[55][55];
int perm[55];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 1; i <= n - 2; i++){
		bool done = 0;
		for(int j = 1; j <= n; j++){
			if(perm[j] || done) continue;
			int cnt = 0;
			for(int k = 1; k <= n; k++)
				if(A[j][k] == i) cnt++;
			if(cnt == n - i){
				perm[j] = i;
				done = 1;
			}
		}
	}

	// check for all

	for(int j = 1; j <= n; j++){
		int cnt[55] = {0};
		for(int k = 1; k <= n; k++){
			cnt[A[j][k]]++;
		}
		bool valid = 1;
		for(int i = 1; i <= n - 1; i++) if(cnt[i] != 1) valid = 0;
		if(valid){
			perm[j] = n;
			break;
		}
	}

	for(int i = 1; i <= n; i++) if(!perm[i]) perm[i] = n - 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			assert(min(perm[i], perm[j]) == A[i][j]);
	for(int i = 1; i <= n; i++) cout << perm[i] << " ";
}