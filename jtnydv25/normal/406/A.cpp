#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define prll(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
const int N = 1005;
int R[N], C[N], A[N][N];
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			sd(A[i][j]);
			R[i] ^= A[i][j];
			C[j] ^= A[i][j];
		}
	}
	int currans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			currans ^= (A[i][j] * A[j][i]);

	int q;
	sd(q);
	while(q--){
		int type;
		sd(type);
		if(type <= 2){
			int i;
			sd(i);
			A[i][i] ^= 1;
			currans ^= 1;
		}
		if(type == 3){
			printf("%d", currans);
		}
	}
}