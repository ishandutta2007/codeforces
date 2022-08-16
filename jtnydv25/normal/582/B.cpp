#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int A[N];
struct S{
	int dp[N][N];
	S(){memset(dp, 0, sizeof dp);}
	int get_dp(int a[], int n){
		int F[N][N]; memset(F, 0, sizeof F);
		for(int i = 0; i < n; i++){
			F[i][i] = 1; dp[a[i]][a[i]] = max(dp[a[i]][a[i]], 1);
			for(int j = i - 1; j >= 0; j--){
				if(a[j] > a[i]) continue;
				for(int k = j + 1; k <= i; k++)
					if(a[k] >= a[j]) F[j][i] = max(F[j][i], 1 + F[k][i]);
				dp[a[j]][a[i]] = max(dp[a[j]][a[i]], F[j][i]);
			}
		}
	}
	S operator * (const S & S1){
		S ret;
		for(int i = 0; i < N; i++){
			for(int j = i; j < N; j++){
				for(int k = j; k < N; k++){
					for(int l = k; l < N; l++){
						ret.dp[i][l] = max(ret.dp[i][l], dp[i][j] + S1.dp[k][l]);
					}
				}
			}
		}
		return ret;
	}
	void print(int n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j ++) cerr << dp[i][j] << " ";
			cerr << endl;
		}
	}
};
set<int> st;
int mapping[5 * N];
int main(){
	int n, T;
	cin >> n >> T;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		st.insert(A[i]);
	}
	int cnt = 0;
	for(int x : st) mapping[x] = cnt++;
	for(int i = 0; i < n; i++){
		A[i] = mapping[A[i]];
	}
	S ret, state;
	state.get_dp(A, n);
	for(; T; state = (state * state), T >>= 1) if(T & 1){
		ret = (ret * state);
	}
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = i; j < N; j++) ans = max(ans, ret.dp[i][j]);
	printf("%d", ans)	;
}