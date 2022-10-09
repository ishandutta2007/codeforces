#include "bits/stdc++.h"
using namespace std;

const long long mul = 1ll << 50ll;

long long A[1005], K, N, Divs[10005], DC;
long long DP[2][10005];
bool Uzet[1005][10005];

long long gcd(long long a, long long b){
	long long t;
	while (b){
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void read(){
	cin >> N >> K;
	for (long long i=1; i<=N; i++){
		cin >> A[i];
	}
	
	if (K == 1){
		cout << 1 << "\n" << min_element(A+1, A+N+1) - A;
		exit(0);
	}
}

unordered_map<long long, int> divId;

void get_divs(){
	for (long long i=1; i*i <= K; i++){
		if (i*i == K){
			Divs[++DC] = i;
		} else if (K%i == 0){
			Divs[++DC] = i;
			Divs[++DC] = K/i;
		}
	}
	sort(Divs+1, Divs+DC+1);
	for (int i=1; i<=DC; i++) divId[Divs[i]] = i;
}

void dp(){

	memset(DP, 63, sizeof(DP));
	DP[0][1] = 0;
	for (int i=1; i<=N; i++){
		int nu = i & 1;
		int ol = 1 - nu;
		memset(DP[nu], 63, sizeof(DP[nu]));
		for (int j=1; j<=DC; j++){
			long long probaj = Divs[j] / gcd(A[i], Divs[j]);
			int pid = divId[probaj];
			DP[nu][j] = DP[ol][pid] + mul + A[i];
			Uzet[i][j] = true;
			if (DP[ol][j] < DP[nu][j]){
				DP[nu][j] = DP[ol][j];
				Uzet[i][j] = false;
			}
		}
	}
	
	int pid = DC;
	int n = N;	
	
	if (DP[n % 2][pid] <= 1337 * mul){
		cout << DP[n % 2][pid] / mul << endl;
		while (n > 0){
			if (Uzet[n][pid]){
				pid = divId[Divs[pid] / gcd(A[n], Divs[pid])];
				cout << n << ' ';
			}
			n--;
		}
	} else {
		cout << -1;
	}
}

int main(){
	read();
	get_divs();
	dp();
	return 0;
}