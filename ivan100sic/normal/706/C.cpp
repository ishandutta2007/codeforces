#include "bits/stdc++.h"
using namespace std;

char Buff[100005];
string S[100005];
int C[100005], N;
long long D[100005][2];

string rev(string x){
	reverse(x.begin(), x.end());
	return x;
}

int main(){
	memset(D, 63, sizeof(D));
	
	scanf("%d", &N);
	for (int i=1; i<=N; i++) scanf("%d", C+i);
	for (int i=1; i<=N; i++){
		scanf("%s", Buff);
		S[i] = string(Buff);
	}
	
	D[1][0] = 0;
	D[1][1] = C[1];
	
	for (int i=2; i<=N; i++){
		// ord
		if (S[i-1] <= S[i]){
			D[i][0] = min(D[i][0], D[i-1][0]);
		}
		if (rev(S[i-1]) <= S[i]){
			D[i][0] = min(D[i][0], D[i-1][1]);
		}
		
		// rev
		if (S[i-1] <= rev(S[i])){
			D[i][1] = min(D[i][1], D[i-1][0] + C[i]);
		}
		if (rev(S[i-1]) <= rev(S[i])){
			D[i][1] = min(D[i][1], D[i-1][1] + C[i]);
		}	
	}
	
	long long sol = min(D[N][0], D[N][1]);
	
	if (sol > 1.1e15){
		sol = -1;
	}
	
	cout << sol << endl;
	return 0;
}