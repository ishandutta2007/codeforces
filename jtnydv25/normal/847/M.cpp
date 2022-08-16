#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
#define pb push_back
const int N = 105;
int A[N];
int main(){
	int i, j, k, n, m, t;
	cin >> n;
	for(i = 1; i <= n; i++) cin >> A[i];
	int d = A[2] - A[1];
	for(int i = 3; i <= n; i++){
		if(A[i] != A[i - 1] + d){
			cout << A[n];
			return 0;
		}
	}
	cout << A[n] + d;
}