#include <bits/stdc++.h>
using namespace std;

#define ld double

double P[105];
int main(){
	ld prob;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> P[i];
	sort(P + 1, P + n + 1);
	prob = P[n];
	ld prod = 1. - prob;
	for(int i = n - 1; i >= 1; i--){
		// try adding i
		ld newprob = prob * (1. - P[i]) + P[i] * prod;
		if(newprob > prob){
			prob = newprob;
			prod *= (1. - P[i]);
		}
	}
	cout << setprecision(15) << fixed << prob << endl;
}